/*
    This file is part of the WebKit open source project.
    This file has been generated by generate-bindings.pl. DO NOT MODIFY!

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Library General Public
    License as published by the Free Software Foundation; either
    version 2 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Library General Public License for more details.

    You should have received a copy of the GNU Library General Public License
    along with this library; see the file COPYING.LIB.  If not, write to
    the Free Software Foundation, Inc., 59 Temple Place - Suite 330,
    Boston, MA 02111-1307, USA.
*/

#include "config.h"
#if ENABLE(Condition1) || ENABLE(Condition2)
#include "V8TestInterface.h"

#include "BindingState.h"
#include "ContextFeatures.h"
#include "ExceptionCode.h"
#include "Frame.h"
#include "RuntimeEnabledFeatures.h"
#include "TestSupplemental.h"
#include "V8Binding.h"
#include "V8DOMWrapper.h"
#include "V8Node.h"
#include "V8TestObj.h"
#include <wtf/GetPtr.h>
#include <wtf/RefCounted.h>
#include <wtf/RefPtr.h>
#include <wtf/UnusedParam.h>

#if ENABLE(BINDING_INTEGRITY)
#if defined(OS_WIN)
#pragma warning(disable: 4483)
extern "C" { extern void (*const __identifier("??_7TestInterface@WebCore@@6B@")[])(); }
#else
extern "C" { extern void* _ZTVN7WebCore13TestInterfaceE[]; }
#endif
#endif // ENABLE(BINDING_INTEGRITY)

namespace WebCore {

#if ENABLE(BINDING_INTEGRITY)
// This checks if a DOM object that is about to be wrapped is valid.
// Specifically, it checks that a vtable of the DOM object is equal to
// a vtable of an expected class.
// Due to a dangling pointer, the DOM object you are wrapping might be
// already freed or realloced. If freed, the check will fail because
// a free list pointer should be stored at the head of the DOM object.
// If realloced, the check will fail because the vtable of the DOM object
// differs from the expected vtable (unless the same class of DOM object
// is realloced on the slot).
inline void checkTypeOrDieTrying(TestInterface* object)
{
    void* actualVTablePointer = *(reinterpret_cast<void**>(object));
#if defined(OS_WIN)
    void* expectedVTablePointer = reinterpret_cast<void*>(__identifier("??_7TestInterface@WebCore@@6B@"));
#else
    void* expectedVTablePointer = &_ZTVN7WebCore13TestInterfaceE[2];
#endif
    if (actualVTablePointer != expectedVTablePointer)
        CRASH();
}
#endif // ENABLE(BINDING_INTEGRITY)

WrapperTypeInfo V8TestInterface::info = { V8TestInterface::GetTemplate, V8TestInterface::derefObject, V8TestInterface::toActiveDOMObject, 0, 0, V8TestInterface::installPerContextPrototypeProperties, 0, WrapperTypeObjectPrototype };

namespace TestInterfaceV8Internal {

template <typename T> void V8_USE(T) { }

#if ENABLE(Condition11) || ENABLE(Condition12)

static v8::Handle<v8::Value> supplementalStaticReadOnlyAttrAttrGetter(v8::Local<v8::String> name, const v8::AccessorInfo& info)
{
    return v8Integer(TestSupplemental::supplementalStaticReadOnlyAttr(), info.GetIsolate());
}

#endif // ENABLE(Condition11) || ENABLE(Condition12)

#if ENABLE(Condition11) || ENABLE(Condition12)

static v8::Handle<v8::Value> supplementalStaticReadOnlyAttrAttrGetterCallback(v8::Local<v8::String> name, const v8::AccessorInfo& info)
{
    return TestInterfaceV8Internal::supplementalStaticReadOnlyAttrAttrGetter(name, info);
}

#endif // ENABLE(Condition11) || ENABLE(Condition12)

#if ENABLE(Condition11) || ENABLE(Condition12)

static v8::Handle<v8::Value> supplementalStaticAttrAttrGetter(v8::Local<v8::String> name, const v8::AccessorInfo& info)
{
    return v8String(TestSupplemental::supplementalStaticAttr(), info.GetIsolate(), ReturnUnsafeHandle);
}

#endif // ENABLE(Condition11) || ENABLE(Condition12)

#if ENABLE(Condition11) || ENABLE(Condition12)

static v8::Handle<v8::Value> supplementalStaticAttrAttrGetterCallback(v8::Local<v8::String> name, const v8::AccessorInfo& info)
{
    return TestInterfaceV8Internal::supplementalStaticAttrAttrGetter(name, info);
}

#endif // ENABLE(Condition11) || ENABLE(Condition12)

#if ENABLE(Condition11) || ENABLE(Condition12)

static void supplementalStaticAttrAttrSetter(v8::Local<v8::String> name, v8::Local<v8::Value> value, const v8::AccessorInfo& info)
{
    V8TRYCATCH_FOR_V8STRINGRESOURCE_VOID(V8StringResource<>, v, value);
    TestSupplemental::setSupplementalStaticAttr(v);
    return;
}

#endif // ENABLE(Condition11) || ENABLE(Condition12)

#if ENABLE(Condition11) || ENABLE(Condition12)

static void supplementalStaticAttrAttrSetterCallback(v8::Local<v8::String> name, v8::Local<v8::Value> value, const v8::AccessorInfo& info)
{
    TestInterfaceV8Internal::supplementalStaticAttrAttrSetter(name, value, info);
}

#endif // ENABLE(Condition11) || ENABLE(Condition12)

#if ENABLE(Condition11) || ENABLE(Condition12)

static v8::Handle<v8::Value> supplementalStr1AttrGetter(v8::Local<v8::String> name, const v8::AccessorInfo& info)
{
    TestInterface* imp = V8TestInterface::toNative(info.Holder());
    return v8String(TestSupplemental::supplementalStr1(imp), info.GetIsolate(), ReturnUnsafeHandle);
}

#endif // ENABLE(Condition11) || ENABLE(Condition12)

#if ENABLE(Condition11) || ENABLE(Condition12)

static v8::Handle<v8::Value> supplementalStr1AttrGetterCallback(v8::Local<v8::String> name, const v8::AccessorInfo& info)
{
    return TestInterfaceV8Internal::supplementalStr1AttrGetter(name, info);
}

#endif // ENABLE(Condition11) || ENABLE(Condition12)

#if ENABLE(Condition11) || ENABLE(Condition12)

static v8::Handle<v8::Value> supplementalStr2AttrGetter(v8::Local<v8::String> name, const v8::AccessorInfo& info)
{
    TestInterface* imp = V8TestInterface::toNative(info.Holder());
    return v8String(TestSupplemental::supplementalStr2(imp), info.GetIsolate(), ReturnUnsafeHandle);
}

#endif // ENABLE(Condition11) || ENABLE(Condition12)

#if ENABLE(Condition11) || ENABLE(Condition12)

static v8::Handle<v8::Value> supplementalStr2AttrGetterCallback(v8::Local<v8::String> name, const v8::AccessorInfo& info)
{
    return TestInterfaceV8Internal::supplementalStr2AttrGetter(name, info);
}

#endif // ENABLE(Condition11) || ENABLE(Condition12)

#if ENABLE(Condition11) || ENABLE(Condition12)

static void supplementalStr2AttrSetter(v8::Local<v8::String> name, v8::Local<v8::Value> value, const v8::AccessorInfo& info)
{
    TestInterface* imp = V8TestInterface::toNative(info.Holder());
    V8TRYCATCH_FOR_V8STRINGRESOURCE_VOID(V8StringResource<>, v, value);
    TestSupplemental::setSupplementalStr2(imp, v);
    return;
}

#endif // ENABLE(Condition11) || ENABLE(Condition12)

#if ENABLE(Condition11) || ENABLE(Condition12)

static void supplementalStr2AttrSetterCallback(v8::Local<v8::String> name, v8::Local<v8::Value> value, const v8::AccessorInfo& info)
{
    TestInterfaceV8Internal::supplementalStr2AttrSetter(name, value, info);
}

#endif // ENABLE(Condition11) || ENABLE(Condition12)

#if ENABLE(Condition11) || ENABLE(Condition12)

static v8::Handle<v8::Value> supplementalStr3AttrGetterCallback(v8::Local<v8::String> name, const v8::AccessorInfo& info)
{
    return V8TestInterface::supplementalStr3AttrGetterCustom(name, info);
}

#endif // ENABLE(Condition11) || ENABLE(Condition12)

#if ENABLE(Condition11) || ENABLE(Condition12)

static void supplementalStr3AttrSetterCallback(v8::Local<v8::String> name, v8::Local<v8::Value> value, const v8::AccessorInfo& info)
{
    V8TestInterface::supplementalStr3AttrSetterCustom(name, value, info);
}

#endif // ENABLE(Condition11) || ENABLE(Condition12)

#if ENABLE(Condition11) || ENABLE(Condition12)

static v8::Handle<v8::Value> supplementalNodeAttrGetter(v8::Local<v8::String> name, const v8::AccessorInfo& info)
{
    TestInterface* imp = V8TestInterface::toNative(info.Holder());
    return toV8Fast(TestSupplemental::supplementalNode(imp), info, imp);
}

#endif // ENABLE(Condition11) || ENABLE(Condition12)

#if ENABLE(Condition11) || ENABLE(Condition12)

static v8::Handle<v8::Value> supplementalNodeAttrGetterCallback(v8::Local<v8::String> name, const v8::AccessorInfo& info)
{
    return TestInterfaceV8Internal::supplementalNodeAttrGetter(name, info);
}

#endif // ENABLE(Condition11) || ENABLE(Condition12)

#if ENABLE(Condition11) || ENABLE(Condition12)

static void supplementalNodeAttrSetter(v8::Local<v8::String> name, v8::Local<v8::Value> value, const v8::AccessorInfo& info)
{
    TestInterface* imp = V8TestInterface::toNative(info.Holder());
    Node* v = V8Node::HasInstance(value, info.GetIsolate()) ? V8Node::toNative(v8::Handle<v8::Object>::Cast(value)) : 0;
    TestSupplemental::setSupplementalNode(imp, WTF::getPtr(v));
    return;
}

#endif // ENABLE(Condition11) || ENABLE(Condition12)

#if ENABLE(Condition11) || ENABLE(Condition12)

static void supplementalNodeAttrSetterCallback(v8::Local<v8::String> name, v8::Local<v8::Value> value, const v8::AccessorInfo& info)
{
    TestInterfaceV8Internal::supplementalNodeAttrSetter(name, value, info);
}

#endif // ENABLE(Condition11) || ENABLE(Condition12)

#if ENABLE(Condition11) || ENABLE(Condition12)

static v8::Handle<v8::Value> supplementalMethod1Method(const v8::Arguments& args)
{
    TestInterface* imp = V8TestInterface::toNative(args.Holder());
    TestSupplemental::supplementalMethod1(imp);
    return v8Undefined();
}

#endif // ENABLE(Condition11) || ENABLE(Condition12)

#if ENABLE(Condition11) || ENABLE(Condition12)

static v8::Handle<v8::Value> supplementalMethod1MethodCallback(const v8::Arguments& args)
{
    return TestInterfaceV8Internal::supplementalMethod1Method(args);
}

#endif // ENABLE(Condition11) || ENABLE(Condition12)

#if ENABLE(Condition11) || ENABLE(Condition12)

static v8::Handle<v8::Value> supplementalMethod2Method(const v8::Arguments& args)
{
    if (args.Length() < 2)
        return throwNotEnoughArgumentsError(args.GetIsolate());
    TestInterface* imp = V8TestInterface::toNative(args.Holder());
    ExceptionCode ec = 0;
    {
    V8TRYCATCH_FOR_V8STRINGRESOURCE(V8StringResource<>, strArg, args[0]);
    V8TRYCATCH(TestObj*, objArg, V8TestObj::HasInstance(args[1], args.GetIsolate()) ? V8TestObj::toNative(v8::Handle<v8::Object>::Cast(args[1])) : 0);
    ScriptExecutionContext* scriptContext = getScriptExecutionContext();
    RefPtr<TestObj> result = TestSupplemental::supplementalMethod2(scriptContext, imp, strArg, objArg, ec);
    if (UNLIKELY(ec))
        goto fail;
    return toV8(result.release(), args.Holder(), args.GetIsolate());
    }
    fail:
    return setDOMException(ec, args.GetIsolate());
}

#endif // ENABLE(Condition11) || ENABLE(Condition12)

#if ENABLE(Condition11) || ENABLE(Condition12)

static v8::Handle<v8::Value> supplementalMethod2MethodCallback(const v8::Arguments& args)
{
    return TestInterfaceV8Internal::supplementalMethod2Method(args);
}

#endif // ENABLE(Condition11) || ENABLE(Condition12)

#if ENABLE(Condition11) || ENABLE(Condition12)

static v8::Handle<v8::Value> supplementalMethod3MethodCallback(const v8::Arguments& args)
{
    return V8TestInterface::supplementalMethod3MethodCustom(args);
}

#endif // ENABLE(Condition11) || ENABLE(Condition12)

#if ENABLE(Condition11) || ENABLE(Condition12)

static v8::Handle<v8::Value> supplementalMethod4Method(const v8::Arguments& args)
{
    TestSupplemental::supplementalMethod4();
    return v8Undefined();
}

#endif // ENABLE(Condition11) || ENABLE(Condition12)

#if ENABLE(Condition11) || ENABLE(Condition12)

static v8::Handle<v8::Value> supplementalMethod4MethodCallback(const v8::Arguments& args)
{
    return TestInterfaceV8Internal::supplementalMethod4Method(args);
}

#endif // ENABLE(Condition11) || ENABLE(Condition12)

static v8::Handle<v8::Value> constructor(const v8::Arguments& args)
{
    if (args.Length() < 1)
        return throwNotEnoughArgumentsError(args.GetIsolate());

    ExceptionCode ec = 0;
    V8TRYCATCH_FOR_V8STRINGRESOURCE(V8StringResource<>, str1, args[0]);
    V8TRYCATCH_FOR_V8STRINGRESOURCE(V8StringResource<>, str2, args[1]);

    ScriptExecutionContext* context = getScriptExecutionContext();

    RefPtr<TestInterface> impl = TestInterface::create(context, str1, str2, ec);
    v8::Handle<v8::Object> wrapper = args.Holder();
    if (ec)
        goto fail;

    V8DOMWrapper::associateObjectWithWrapper(impl.release(), &V8TestInterface::info, wrapper, args.GetIsolate(), WrapperConfiguration::Dependent);
    return wrapper;
    fail:
    return setDOMException(ec, args.GetIsolate());
}

} // namespace TestInterfaceV8Internal

static const V8DOMConfiguration::BatchedAttribute V8TestInterfaceAttrs[] = {
#if ENABLE(Condition11) || ENABLE(Condition12)
    // Attribute 'supplementalStaticReadOnlyAttr' (Type: 'readonly attribute' ExtAttr: 'Conditional ImplementedBy')
    {"supplementalStaticReadOnlyAttr", TestInterfaceV8Internal::supplementalStaticReadOnlyAttrAttrGetterCallback, 0, 0 /* no data */, static_cast<v8::AccessControl>(v8::DEFAULT), static_cast<v8::PropertyAttribute>(v8::None), 0 /* on instance */},
#endif // ENABLE(Condition11) || ENABLE(Condition12)
#if ENABLE(Condition11) || ENABLE(Condition12)
    // Attribute 'supplementalStaticAttr' (Type: 'attribute' ExtAttr: 'Conditional ImplementedBy')
    {"supplementalStaticAttr", TestInterfaceV8Internal::supplementalStaticAttrAttrGetterCallback, TestInterfaceV8Internal::supplementalStaticAttrAttrSetterCallback, 0 /* no data */, static_cast<v8::AccessControl>(v8::DEFAULT), static_cast<v8::PropertyAttribute>(v8::None), 0 /* on instance */},
#endif // ENABLE(Condition11) || ENABLE(Condition12)
#if ENABLE(Condition11) || ENABLE(Condition12)
    // Attribute 'supplementalStr1' (Type: 'readonly attribute' ExtAttr: 'Conditional ImplementedBy')
    {"supplementalStr1", TestInterfaceV8Internal::supplementalStr1AttrGetterCallback, 0, 0 /* no data */, static_cast<v8::AccessControl>(v8::DEFAULT), static_cast<v8::PropertyAttribute>(v8::None), 0 /* on instance */},
#endif // ENABLE(Condition11) || ENABLE(Condition12)
#if ENABLE(Condition11) || ENABLE(Condition12)
    // Attribute 'supplementalStr2' (Type: 'attribute' ExtAttr: 'Conditional ImplementedBy')
    {"supplementalStr2", TestInterfaceV8Internal::supplementalStr2AttrGetterCallback, TestInterfaceV8Internal::supplementalStr2AttrSetterCallback, 0 /* no data */, static_cast<v8::AccessControl>(v8::DEFAULT), static_cast<v8::PropertyAttribute>(v8::None), 0 /* on instance */},
#endif // ENABLE(Condition11) || ENABLE(Condition12)
#if ENABLE(Condition11) || ENABLE(Condition12)
    // Attribute 'supplementalStr3' (Type: 'attribute' ExtAttr: 'CustomSetter CustomGetter Conditional ImplementedBy')
    {"supplementalStr3", TestInterfaceV8Internal::supplementalStr3AttrGetterCallback, TestInterfaceV8Internal::supplementalStr3AttrSetterCallback, 0 /* no data */, static_cast<v8::AccessControl>(v8::DEFAULT), static_cast<v8::PropertyAttribute>(v8::None), 0 /* on instance */},
#endif // ENABLE(Condition11) || ENABLE(Condition12)
#if ENABLE(Condition11) || ENABLE(Condition12)
    // Attribute 'supplementalNode' (Type: 'attribute' ExtAttr: 'Conditional ImplementedBy')
    {"supplementalNode", TestInterfaceV8Internal::supplementalNodeAttrGetterCallback, TestInterfaceV8Internal::supplementalNodeAttrSetterCallback, 0 /* no data */, static_cast<v8::AccessControl>(v8::DEFAULT), static_cast<v8::PropertyAttribute>(v8::None), 0 /* on instance */},
#endif // ENABLE(Condition11) || ENABLE(Condition12)
};

static const V8DOMConfiguration::BatchedMethod V8TestInterfaceMethods[] = {
#if ENABLE(Condition11) || ENABLE(Condition12)
    {"supplementalMethod1", TestInterfaceV8Internal::supplementalMethod1MethodCallback},
#endif
#if ENABLE(Condition11) || ENABLE(Condition12)
    {"supplementalMethod3", TestInterfaceV8Internal::supplementalMethod3MethodCallback},
#endif
};

static const V8DOMConfiguration::BatchedConstant V8TestInterfaceConsts[] = {
#if ENABLE(Condition11) || ENABLE(Condition12)
    {"SUPPLEMENTALCONSTANT1", static_cast<signed int>(1)},
#endif
#if ENABLE(Condition11) || ENABLE(Condition12)
    {"SUPPLEMENTALCONSTANT2", static_cast<signed int>(2)},
#endif
};


#if ENABLE(Condition11) || ENABLE(Condition12)
COMPILE_ASSERT(1 == TestSupplemental::SUPPLEMENTALCONSTANT1, TestInterfaceEnumSUPPLEMENTALCONSTANT1IsWrongUseDoNotCheckConstants);
#endif
#if ENABLE(Condition11) || ENABLE(Condition12)
COMPILE_ASSERT(2 == TestSupplemental::CONST_IMPL, TestInterfaceEnumCONST_IMPLIsWrongUseDoNotCheckConstants);
#endif

v8::Handle<v8::Value> V8TestInterface::constructorCallback(const v8::Arguments& args)
{
    if (!args.IsConstructCall())
        return throwTypeError("DOM object constructor cannot be called as a function.", args.GetIsolate());

    if (ConstructorMode::current() == ConstructorMode::WrapExistingObject)
        return args.Holder();

    return TestInterfaceV8Internal::constructor(args);
}

static v8::Persistent<v8::FunctionTemplate> ConfigureV8TestInterfaceTemplate(v8::Persistent<v8::FunctionTemplate> desc, v8::Isolate* isolate, WrapperWorldType worldType)
{
    desc->ReadOnlyPrototype();

    v8::Local<v8::Signature> defaultSignature;
    defaultSignature = V8DOMConfiguration::configureTemplate(desc, "TestInterface", v8::Persistent<v8::FunctionTemplate>(), V8TestInterface::internalFieldCount,
        V8TestInterfaceAttrs, WTF_ARRAY_LENGTH(V8TestInterfaceAttrs),
        V8TestInterfaceMethods, WTF_ARRAY_LENGTH(V8TestInterfaceMethods), isolate);
    UNUSED_PARAM(defaultSignature); // In some cases, it will not be used.
#if ENABLE(TEST_INTERFACE)
    desc->SetCallHandler(V8TestInterface::constructorCallback);
#endif // ENABLE(TEST_INTERFACE)
    v8::Local<v8::ObjectTemplate> instance = desc->InstanceTemplate();
    v8::Local<v8::ObjectTemplate> proto = desc->PrototypeTemplate();
    UNUSED_PARAM(instance); // In some cases, it will not be used.
    UNUSED_PARAM(proto); // In some cases, it will not be used.
    

    // Custom Signature 'supplementalMethod2'
    const int supplementalMethod2Argc = 2;
    v8::Handle<v8::FunctionTemplate> supplementalMethod2Argv[supplementalMethod2Argc] = { v8::Handle<v8::FunctionTemplate>(), V8TestObj::GetRawTemplate(isolate) };
    v8::Handle<v8::Signature> supplementalMethod2Signature = v8::Signature::New(desc, supplementalMethod2Argc, supplementalMethod2Argv);
#if ENABLE(Condition11) || ENABLE(Condition12)
    proto->Set(v8::String::NewSymbol("supplementalMethod2"), v8::FunctionTemplate::New(TestInterfaceV8Internal::supplementalMethod2MethodCallback, v8Undefined(), supplementalMethod2Signature));
#endif // ENABLE(Condition11) || ENABLE(Condition12)
#if ENABLE(Condition11) || ENABLE(Condition12)
    desc->Set(v8::String::NewSymbol("supplementalMethod4"), v8::FunctionTemplate::New(TestInterfaceV8Internal::supplementalMethod4MethodCallback, v8Undefined(), v8::Local<v8::Signature>()));
#endif // ENABLE(Condition11) || ENABLE(Condition12)
    V8DOMConfiguration::batchConfigureConstants(desc, proto, V8TestInterfaceConsts, WTF_ARRAY_LENGTH(V8TestInterfaceConsts), isolate);

    // Custom toString template
    desc->Set(v8::String::NewSymbol("toString"), V8PerIsolateData::current()->toStringTemplate());
    return desc;
}

v8::Persistent<v8::FunctionTemplate> V8TestInterface::GetRawTemplate(v8::Isolate* isolate)
{
    V8PerIsolateData* data = V8PerIsolateData::from(isolate);
    V8PerIsolateData::TemplateMap::iterator result = data->rawTemplateMap().find(&info);
    if (result != data->rawTemplateMap().end())
        return result->value;

    v8::HandleScope handleScope;
    v8::Persistent<v8::FunctionTemplate> templ = createRawTemplate(isolate);
    data->rawTemplateMap().add(&info, templ);
    return templ;
}

v8::Persistent<v8::FunctionTemplate> V8TestInterface::GetTemplate(v8::Isolate* isolate, WrapperWorldType worldType)
{
    V8PerIsolateData* data = V8PerIsolateData::from(isolate);
    V8PerIsolateData::TemplateMap::iterator result = data->templateMap().find(&info);
    if (result != data->templateMap().end())
        return result->value;

    v8::HandleScope handleScope;
    v8::Persistent<v8::FunctionTemplate> templ =
        ConfigureV8TestInterfaceTemplate(GetRawTemplate(isolate), isolate, worldType);
    data->templateMap().add(&info, templ);
    return templ;
}

bool V8TestInterface::HasInstance(v8::Handle<v8::Value> value, v8::Isolate* isolate)
{
    return GetRawTemplate(isolate)->HasInstance(value);
}

ActiveDOMObject* V8TestInterface::toActiveDOMObject(v8::Handle<v8::Object> object)
{
    return toNative(object);
}


v8::Handle<v8::Object> V8TestInterface::createWrapper(PassRefPtr<TestInterface> impl, v8::Handle<v8::Object> creationContext, v8::Isolate* isolate)
{
    ASSERT(impl.get());
    ASSERT(DOMDataStore::getWrapper(impl.get(), isolate).IsEmpty());

#if ENABLE(BINDING_INTEGRITY)
    checkTypeOrDieTrying(impl.get());
#endif

    v8::Handle<v8::Object> wrapper = V8DOMWrapper::createWrapper(creationContext, &info, impl.get(), isolate);
    if (UNLIKELY(wrapper.IsEmpty()))
        return wrapper;

    installPerContextProperties(wrapper, impl.get(), isolate);
    V8DOMWrapper::associateObjectWithWrapper(impl, &info, wrapper, isolate, hasDependentLifetime ? WrapperConfiguration::Dependent : WrapperConfiguration::Independent);
    return wrapper;
}
void V8TestInterface::derefObject(void* object)
{
    static_cast<TestInterface*>(object)->deref();
}

} // namespace WebCore

#endif // ENABLE(Condition1) || ENABLE(Condition2)
