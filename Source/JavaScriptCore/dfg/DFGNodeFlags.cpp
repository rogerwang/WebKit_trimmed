/*
 * Copyright (C) 2012, 2013 Apple Inc. All rights reserved.
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
 * THIS SOFTWARE IS PROVIDED BY APPLE INC. ``AS IS'' AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL APPLE INC. OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY
 * OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE. 
 */

#include "config.h"
#include "DFGNodeFlags.h"

#if ENABLE(DFG_JIT)

#include <wtf/BoundsCheckedPointer.h>

namespace JSC { namespace DFG {

const char* nodeFlagsAsString(NodeFlags flags)
{
    if (!(flags ^ NodeDoesNotExit))
        return "<empty>";

    static const int size = 128;
    static char description[size];
    BoundsCheckedPointer<char> ptr(description, size);
    
    bool hasPrinted = false;
    
    if (flags & NodeResultMask) {
        switch (flags & NodeResultMask) {
        case NodeResultJS:
            ptr.strcat("JS");
            break;
        case NodeResultNumber:
            ptr.strcat("Number");
            break;
        case NodeResultInt32:
            ptr.strcat("Int32");
            break;
        case NodeResultBoolean:
            ptr.strcat("Boolean");
            break;
        case NodeResultStorage:
            ptr.strcat("Storage");
            break;
        default:
            RELEASE_ASSERT_NOT_REACHED();
            break;
        }
        hasPrinted = true;
    }
    
    if (flags & NodeMustGenerate) {
        if (hasPrinted)
            ptr.strcat("|");
        ptr.strcat("MustGen");
        hasPrinted = true;
    }
    
    if (flags & NodeHasVarArgs) {
        if (hasPrinted)
            ptr.strcat("|");
        ptr.strcat("VarArgs");
        hasPrinted = true;
    }
    
    if (flags & NodeClobbersWorld) {
        if (hasPrinted)
            ptr.strcat("|");
        ptr.strcat("Clobbers");
        hasPrinted = true;
    }
    
    if (flags & NodeMightClobber) {
        if (hasPrinted)
            ptr.strcat("|");
        ptr.strcat("MightClobber");
        hasPrinted = true;
    }
    
    if (flags & NodeResultMask) {
        if (!(flags & NodeUsedAsNumber) && !(flags & NodeNeedsNegZero)) {
            if (hasPrinted)
                ptr.strcat("|");
            ptr.strcat("PureInt");
            hasPrinted = true;
        } else if (!(flags & NodeUsedAsNumber)) {
            if (hasPrinted)
                ptr.strcat("|");
            ptr.strcat("PureInt(w/ neg zero)");
            hasPrinted = true;
        } else if (!(flags & NodeNeedsNegZero)) {
            if (hasPrinted)
                ptr.strcat("|");
            ptr.strcat("PureNum");
            hasPrinted = true;
        }
        if (flags & NodeUsedAsOther) {
            if (hasPrinted)
                ptr.strcat("|");
            ptr.strcat("UseAsOther");
            hasPrinted = true;
        }
    }
    
    if (flags & NodeMayOverflow) {
        if (hasPrinted)
            ptr.strcat("|");
        ptr.strcat("MayOverflow");
        hasPrinted = true;
    }
    
    if (flags & NodeMayNegZero) {
        if (hasPrinted)
            ptr.strcat("|");
        ptr.strcat("MayNegZero");
        hasPrinted = true;
    }
    
    if (flags & NodeUsedAsInt) {
        if (hasPrinted)
            ptr.strcat("|");
        ptr.strcat("UseAsInt");
        hasPrinted = true;
    }
    
    if (!(flags & NodeDoesNotExit)) {
        if (hasPrinted)
            ptr.strcat("|");
        ptr.strcat("CanExit");
        hasPrinted = true;
    }
    
    if (flags & NodeExitsForward) {
        if (hasPrinted)
            ptr.strcat("|");
        ptr.strcat("NodeExitsForward");
        hasPrinted = true;
    }
    
    *ptr++ = 0;
    
    return description;
}


} } // namespace JSC::DFG

#endif // ENABLE(DFG_JIT)

