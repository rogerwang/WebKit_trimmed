/*
 * Copyright (C) 2013 Intel Corporation. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY APPLE INC. AND ITS CONTRIBUTORS ``AS IS''
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL APPLE INC. OR ITS CONTRIBUTORS
 * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
 * THE POSSIBILITY OF SUCH DAMAGE.
 */

#include "config.h"
#include "GLTransportSurface.h"

#if USE(ACCELERATED_COMPOSITING)

namespace WebCore {

static const GLfloat vertices[] = { 0, 0, 1, 0, 1, 1, 0, 1 };
static bool vertexArrayObjectSupported = false;

GLTransportSurface::GLTransportSurface(SurfaceAttributes attributes)
    : GLPlatformSurface(attributes)
    , m_vbo(0)
    , m_vertexHandle(0)
{
}

GLTransportSurface::~GLTransportSurface()
{
}

void GLTransportSurface::updateContents(const uint32_t texture)
{
    if (!m_shaderProgram)
        initializeShaderProgram();

    draw(texture);
    swapBuffers();
}

void GLTransportSurface::setGeometry(const IntRect& newRect)
{
    m_rect = newRect;

    if (!m_shaderProgram)
        return;

    updateTransformationMatrix();
}

void GLTransportSurface::destroy()
{
    m_rect = IntRect();

    ::glBindFramebuffer(GL_FRAMEBUFFER, 0);
    ::glBindTexture(GL_TEXTURE_2D, 0);

    if (!m_shaderProgram || !m_context3D)
        return;

    ::glBindBuffer(GL_ARRAY_BUFFER, 0);

    if (m_vbo)
        ::glDeleteBuffers(1, &m_vbo);

    if (m_vertexHandle) {
        m_context3D->getExtensions()->bindVertexArrayOES(0);
        m_context3D->getExtensions()->deleteVertexArrayOES(m_vertexHandle);
    } else if (m_shaderProgram)
        ::glDisableVertexAttribArray(m_shaderProgram->vertexLocation());

    ::glUseProgram(0);

    m_shaderProgram = nullptr;
    m_context3D = nullptr;
}

void GLTransportSurface::draw(const uint32_t texture)
{
    if (!m_vertexHandle)
        bindArrayBuffer();

    ::glBindTexture(GL_TEXTURE_2D, texture);
    ::glDrawArrays(GL_TRIANGLE_FAN, 0, 4);
}

void GLTransportSurface::bindArrayBuffer() const
{
    ::glEnableVertexAttribArray(m_shaderProgram->vertexLocation());
    ::glBindBuffer(GL_ARRAY_BUFFER, m_vbo);
    ::glVertexAttribPointer(m_shaderProgram->vertexLocation(), 2, GraphicsContext3D::FLOAT, false, 0, 0);
}

void GLTransportSurface::updateTransformationMatrix()
{
    if (!m_shaderProgram)
        return;

    ::glViewport(m_rect.x(), m_rect.y(), m_rect.width(), m_rect.height());

    FloatRect targetRect = FloatRect(m_rect);
    TransformationMatrix identityMatrix;
    TransformationMatrix matrix = TransformationMatrix(identityMatrix).multiply(TransformationMatrix::rectToRect(FloatRect(0, 0, 1, 1), targetRect));
    m_shaderProgram->setMatrix(m_shaderProgram->modelViewMatrixLocation(), matrix);

    // Taken from TextureMapperGL.
    const float nearValue = 9999999;
    const float farValue = -99999;

    TransformationMatrix projectionMatrix = TransformationMatrix(2.0 / float(m_rect.width()), 0, 0, 0,
        0, (-2.0) / float(m_rect.height()), 0, 0,
        0, 0, -2.f / (farValue - nearValue), 0,
        -1, 1, -(farValue + nearValue) / (farValue - nearValue), 1);

    m_shaderProgram->setMatrix(m_shaderProgram->projectionMatrixLocation(), projectionMatrix);
}

void GLTransportSurface::initializeShaderProgram()
{
    if (!m_context3D)
        m_context3D = GraphicsContext3D::createForCurrentGLContext();

    vertexArrayObjectSupported = m_context3D->getExtensions()->supports("GL_OES_vertex_array_object");

    TextureMapperShaderProgram::Options options = TextureMapperShaderProgram::Texture;
    m_shaderProgram = TextureMapperShaderProgram::create(m_context3D, options);

    ::glUseProgram(m_shaderProgram->programID());
    ::glUniform1i(m_shaderProgram->samplerLocation(), 0);
    ::glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    ::glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    ::glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    ::glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

    TransformationMatrix flipTransform;
    flipTransform.flipY();
    flipTransform.translate(0, -1);
    m_shaderProgram->setMatrix(m_shaderProgram->textureSpaceMatrixLocation(), flipTransform);

    ::glUniform1f(m_shaderProgram->opacityLocation(), 1.0);

    if (!m_vbo) {
        ::glGenBuffers(1, &m_vbo);
        ::glBindBuffer(GL_ARRAY_BUFFER, m_vbo);
        ::glBufferData(GL_ARRAY_BUFFER, sizeof(GC3Dfloat) * 8, vertices, GL_STATIC_DRAW);
    }

    // Create and set-up vertex array object.
    if (vertexArrayObjectSupported) {
        m_vertexHandle = m_context3D->getExtensions()->createVertexArrayOES();

        if (m_vertexHandle) {
            m_context3D->getExtensions()->bindVertexArrayOES(m_vertexHandle);
            bindArrayBuffer();
        }
    }

    updateTransformationMatrix();

    ::glBindFramebuffer(GL_FRAMEBUFFER, 0);
}

}

#endif

