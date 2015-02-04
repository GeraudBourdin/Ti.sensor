/**
 * Appcelerator Titanium Mobile
 * Copyright (c) 2011-2013 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License
 * Please see the LICENSE included with this distribution for details.
 */

/** This code is generated, do not edit by hand. **/

#include "com.geraudbourdin.sensor.SensorModule.h"

#include "AndroidUtil.h"
#include "EventEmitter.h"
#include "JNIUtil.h"
#include "JSException.h"
#include "Proxy.h"
#include "ProxyFactory.h"
#include "TypeConverter.h"
#include "V8Util.h"




#include "org.appcelerator.kroll.KrollModule.h"

#define TAG "SensorModule"

using namespace v8;

		namespace com {
		namespace geraudbourdin {
		namespace sensor {


Persistent<FunctionTemplate> SensorModule::proxyTemplate = Persistent<FunctionTemplate>();
jclass SensorModule::javaClass = NULL;

SensorModule::SensorModule(jobject javaObject) : titanium::Proxy(javaObject)
{
}

void SensorModule::bindProxy(Handle<Object> exports)
{
	if (proxyTemplate.IsEmpty()) {
		getProxyTemplate();
	}

	// use symbol over string for efficiency
	Handle<String> nameSymbol = String::NewSymbol("Sensor");

	Local<Function> proxyConstructor = proxyTemplate->GetFunction();
	Local<Object> moduleInstance = proxyConstructor->NewInstance();
	exports->Set(nameSymbol, moduleInstance);
}

void SensorModule::dispose()
{
	LOGD(TAG, "dispose()");
	if (!proxyTemplate.IsEmpty()) {
		proxyTemplate.Dispose();
		proxyTemplate = Persistent<FunctionTemplate>();
	}

	titanium::KrollModule::dispose();
}

Handle<FunctionTemplate> SensorModule::getProxyTemplate()
{
	if (!proxyTemplate.IsEmpty()) {
		return proxyTemplate;
	}

	LOGD(TAG, "GetProxyTemplate");

	javaClass = titanium::JNIUtil::findClass("com/geraudbourdin/sensor/SensorModule");
	HandleScope scope;

	// use symbol over string for efficiency
	Handle<String> nameSymbol = String::NewSymbol("Sensor");

	Handle<FunctionTemplate> t = titanium::Proxy::inheritProxyTemplate(
		titanium::KrollModule::getProxyTemplate()
, javaClass, nameSymbol);

	proxyTemplate = Persistent<FunctionTemplate>::New(t);
	proxyTemplate->Set(titanium::Proxy::inheritSymbol,
		FunctionTemplate::New(titanium::Proxy::inherit<SensorModule>)->GetFunction());

	titanium::ProxyFactory::registerProxyPair(javaClass, *proxyTemplate, true);

	// Method bindings --------------------------------------------------------
	DEFINE_PROTOTYPE_METHOD(proxyTemplate, "getSensorList", SensorModule::getSensorList);
	DEFINE_PROTOTYPE_METHOD(proxyTemplate, "enableSensor", SensorModule::enableSensor);
	DEFINE_PROTOTYPE_METHOD(proxyTemplate, "listSensor", SensorModule::listSensor);
	DEFINE_PROTOTYPE_METHOD(proxyTemplate, "getListSensor", SensorModule::getListSensor);
	DEFINE_PROTOTYPE_METHOD(proxyTemplate, "getSensorInfos", SensorModule::getSensorInfos);
	DEFINE_PROTOTYPE_METHOD(proxyTemplate, "getSensorInfost", SensorModule::getSensorInfost);
	DEFINE_PROTOTYPE_METHOD(proxyTemplate, "setSensor", SensorModule::setSensor);

	Local<ObjectTemplate> prototypeTemplate = proxyTemplate->PrototypeTemplate();
	Local<ObjectTemplate> instanceTemplate = proxyTemplate->InstanceTemplate();

	// Delegate indexed property get and set to the Java proxy.
	instanceTemplate->SetIndexedPropertyHandler(titanium::Proxy::getIndexedProperty,
		titanium::Proxy::setIndexedProperty);

	// Constants --------------------------------------------------------------
	JNIEnv *env = titanium::JNIScope::getEnv();
	if (!env) {
		LOGE(TAG, "Failed to get environment in SensorModule");
		//return;
	}


		DEFINE_INT_CONSTANT(prototypeTemplate, "TYPE_MAGNETIC_FIELD_UNCALIBRATED", 14);

		DEFINE_INT_CONSTANT(prototypeTemplate, "TYPE_ALL", -1);

		DEFINE_INT_CONSTANT(prototypeTemplate, "TYPE_STEP_DETECTOR", 18);

		DEFINE_INT_CONSTANT(prototypeTemplate, "TYPE_GYROSCOPE", 4);

		DEFINE_INT_CONSTANT(prototypeTemplate, "TYPE_PROXIMITY", 8);

		DEFINE_INT_CONSTANT(prototypeTemplate, "TYPE_GYROSCOPE_UNCALIBRATED", 16);

		DEFINE_INT_CONSTANT(prototypeTemplate, "TYPE_STEP_COUNTER", 19);

		DEFINE_INT_CONSTANT(prototypeTemplate, "TYPE_MAGNETIC_FIELD", 2);

		DEFINE_INT_CONSTANT(prototypeTemplate, "TYPE_LIGHT", 5);

		DEFINE_INT_CONSTANT(prototypeTemplate, "TYPE_ORIENTATION", 3);

		DEFINE_INT_CONSTANT(prototypeTemplate, "TYPE_RELATIVE_HUMIDITY", 12);

		DEFINE_INT_CONSTANT(prototypeTemplate, "TYPE_HEART_RATE", 21);

		DEFINE_INT_CONSTANT(prototypeTemplate, "TYPE_LINEAR_ACCELERATION", 10);

		DEFINE_INT_CONSTANT(prototypeTemplate, "TYPE_ROTATION_VECTOR", 11);

		DEFINE_INT_CONSTANT(prototypeTemplate, "TYPE_ACCELEROMETER", 1);

		DEFINE_INT_CONSTANT(prototypeTemplate, "TYPE_GRAVITY", 9);

		DEFINE_INT_CONSTANT(prototypeTemplate, "TYPE_GAME_ROTATION_VECTOR", 15);

		DEFINE_INT_CONSTANT(prototypeTemplate, "TYPE_SIGNIFICANT_MOTION", 17);

		DEFINE_INT_CONSTANT(prototypeTemplate, "TYPE_GEOMAGNETIC_ROTATION_VECTOR", 20);

		DEFINE_INT_CONSTANT(prototypeTemplate, "TYPE_AMBIENT_TEMPERATURE", 13);

		DEFINE_INT_CONSTANT(prototypeTemplate, "ONE_HUNDRED", 100);


	// Dynamic properties -----------------------------------------------------
	instanceTemplate->SetAccessor(String::NewSymbol("sensor"),
			titanium::Proxy::getProperty
			, SensorModule::setter_sensor
, Handle<Value>(), DEFAULT);
	instanceTemplate->SetAccessor(String::NewSymbol("sensorList"),
			titanium::Proxy::getProperty
			, SensorModule::setter_sensorList
, Handle<Value>(), DEFAULT);
	instanceTemplate->SetAccessor(String::NewSymbol("enableSensor"),
			titanium::Proxy::getProperty
			, SensorModule::setter_enableSensor
, Handle<Value>(), DEFAULT);
	instanceTemplate->SetAccessor(String::NewSymbol("sensorInfos"),
			titanium::Proxy::getProperty
			, SensorModule::setter_sensorInfos
, Handle<Value>(), DEFAULT);
	instanceTemplate->SetAccessor(String::NewSymbol("sensorInfost"),
			titanium::Proxy::getProperty
			, SensorModule::setter_sensorInfost
, Handle<Value>(), DEFAULT);

	// Accessors --------------------------------------------------------------

	return proxyTemplate;
}

// Methods --------------------------------------------------------------------
Handle<Value> SensorModule::getSensorList(const Arguments& args)
{
	LOGD(TAG, "getSensorList()");
	HandleScope scope;

	JNIEnv *env = titanium::JNIScope::getEnv();
	if (!env) {
		return titanium::JSException::GetJNIEnvironmentError();
	}
	static jmethodID methodID = NULL;
	if (!methodID) {
		methodID = env->GetMethodID(SensorModule::javaClass, "getSensorList", "(I)[I");
		if (!methodID) {
			const char *error = "Couldn't find proxy method 'getSensorList' with signature '(I)[I'";
			LOGE(TAG, error);
				return titanium::JSException::Error(error);
		}
	}

	titanium::Proxy* proxy = titanium::Proxy::unwrap(args.Holder());

	if (args.Length() < 1) {
		char errorStringBuffer[100];
		sprintf(errorStringBuffer, "getSensorList: Invalid number of arguments. Expected 1 but got %d", args.Length());
		return ThrowException(Exception::Error(String::New(errorStringBuffer)));
	}

	jvalue jArguments[1];




	
	
		if ((titanium::V8Util::isNaN(args[0]) && !args[0]->IsUndefined()) || args[0]->ToString()->Length() == 0) {
			const char *error = "Invalid value, expected type Number.";
			LOGE(TAG, error);
			return titanium::JSException::Error(error);
		}
	if (!args[0]->IsNull()) {
		Local<Number> arg_0 = args[0]->ToNumber();
		jArguments[0].i =
			titanium::TypeConverter::jsNumberToJavaInt(env, arg_0);
	} else {
		jArguments[0].i = NULL;
	}

	jobject javaProxy = proxy->getJavaObject();
	jintArray jResult = (jintArray)env->CallObjectMethodA(javaProxy, methodID, jArguments);



	if (!JavaObject::useGlobalRefs) {
		env->DeleteLocalRef(javaProxy);
	}



	if (env->ExceptionCheck()) {
		Handle<Value> jsException = titanium::JSException::fromJavaException();
		env->ExceptionClear();
		return jsException;
	}

	if (jResult == NULL) {
		return Null();
	}

	Handle<Array> v8Result = titanium::TypeConverter::javaArrayToJsArray(env, jResult);

	env->DeleteLocalRef(jResult);


	return v8Result;

}
Handle<Value> SensorModule::enableSensor(const Arguments& args)
{
	LOGD(TAG, "enableSensor()");
	HandleScope scope;

	JNIEnv *env = titanium::JNIScope::getEnv();
	if (!env) {
		return titanium::JSException::GetJNIEnvironmentError();
	}
	static jmethodID methodID = NULL;
	if (!methodID) {
		methodID = env->GetMethodID(SensorModule::javaClass, "enableSensor", "(Ljava/lang/String;)V");
		if (!methodID) {
			const char *error = "Couldn't find proxy method 'enableSensor' with signature '(Ljava/lang/String;)V'";
			LOGE(TAG, error);
				return titanium::JSException::Error(error);
		}
	}

	titanium::Proxy* proxy = titanium::Proxy::unwrap(args.Holder());

	if (args.Length() < 1) {
		char errorStringBuffer[100];
		sprintf(errorStringBuffer, "enableSensor: Invalid number of arguments. Expected 1 but got %d", args.Length());
		return ThrowException(Exception::Error(String::New(errorStringBuffer)));
	}

	jvalue jArguments[1];




	
	
	if (!args[0]->IsNull()) {
		Local<Value> arg_0 = args[0];
		jArguments[0].l =
			titanium::TypeConverter::jsValueToJavaString(env, arg_0);
	} else {
		jArguments[0].l = NULL;
	}

	jobject javaProxy = proxy->getJavaObject();
	env->CallVoidMethodA(javaProxy, methodID, jArguments);

	if (!JavaObject::useGlobalRefs) {
		env->DeleteLocalRef(javaProxy);
	}



				env->DeleteLocalRef(jArguments[0].l);


	if (env->ExceptionCheck()) {
		titanium::JSException::fromJavaException();
		env->ExceptionClear();
	}




	return v8::Undefined();

}
Handle<Value> SensorModule::listSensor(const Arguments& args)
{
	LOGD(TAG, "listSensor()");
	HandleScope scope;

	JNIEnv *env = titanium::JNIScope::getEnv();
	if (!env) {
		return titanium::JSException::GetJNIEnvironmentError();
	}
	static jmethodID methodID = NULL;
	if (!methodID) {
		methodID = env->GetMethodID(SensorModule::javaClass, "listSensor", "()Ljava/util/ArrayList<java/lang/String>;");
		if (!methodID) {
			const char *error = "Couldn't find proxy method 'listSensor' with signature '()Ljava/util/ArrayList<java/lang/String>;'";
			LOGE(TAG, error);
				return titanium::JSException::Error(error);
		}
	}

	titanium::Proxy* proxy = titanium::Proxy::unwrap(args.Holder());

	jvalue* jArguments = 0;

	jobject javaProxy = proxy->getJavaObject();
	jobject jResult = (jobject)env->CallObjectMethodA(javaProxy, methodID, jArguments);



	if (!JavaObject::useGlobalRefs) {
		env->DeleteLocalRef(javaProxy);
	}



	if (env->ExceptionCheck()) {
		Handle<Value> jsException = titanium::JSException::fromJavaException();
		env->ExceptionClear();
		return jsException;
	}

	if (jResult == NULL) {
		return Null();
	}

	Handle<Value> v8Result = titanium::TypeConverter::javaObjectToJsValue(env, jResult);

	env->DeleteLocalRef(jResult);


	return v8Result;

}
Handle<Value> SensorModule::getListSensor(const Arguments& args)
{
	LOGD(TAG, "getListSensor()");
	HandleScope scope;

	JNIEnv *env = titanium::JNIScope::getEnv();
	if (!env) {
		return titanium::JSException::GetJNIEnvironmentError();
	}
	static jmethodID methodID = NULL;
	if (!methodID) {
		methodID = env->GetMethodID(SensorModule::javaClass, "getListSensor", "()[Ljava/lang/String;");
		if (!methodID) {
			const char *error = "Couldn't find proxy method 'getListSensor' with signature '()[Ljava/lang/String;'";
			LOGE(TAG, error);
				return titanium::JSException::Error(error);
		}
	}

	titanium::Proxy* proxy = titanium::Proxy::unwrap(args.Holder());

	jvalue* jArguments = 0;

	jobject javaProxy = proxy->getJavaObject();
	jobjectArray jResult = (jobjectArray)env->CallObjectMethodA(javaProxy, methodID, jArguments);



	if (!JavaObject::useGlobalRefs) {
		env->DeleteLocalRef(javaProxy);
	}



	if (env->ExceptionCheck()) {
		Handle<Value> jsException = titanium::JSException::fromJavaException();
		env->ExceptionClear();
		return jsException;
	}

	if (jResult == NULL) {
		return Null();
	}

	Handle<Array> v8Result = titanium::TypeConverter::javaArrayToJsArray(env, jResult);

	env->DeleteLocalRef(jResult);


	return v8Result;

}
Handle<Value> SensorModule::getSensorInfos(const Arguments& args)
{
	LOGD(TAG, "getSensorInfos()");
	HandleScope scope;

	JNIEnv *env = titanium::JNIScope::getEnv();
	if (!env) {
		return titanium::JSException::GetJNIEnvironmentError();
	}
	static jmethodID methodID = NULL;
	if (!methodID) {
		methodID = env->GetMethodID(SensorModule::javaClass, "getSensorInfos", "(I)Lorg/appcelerator/kroll/KrollDict;");
		if (!methodID) {
			const char *error = "Couldn't find proxy method 'getSensorInfos' with signature '(I)Lorg/appcelerator/kroll/KrollDict;'";
			LOGE(TAG, error);
				return titanium::JSException::Error(error);
		}
	}

	titanium::Proxy* proxy = titanium::Proxy::unwrap(args.Holder());

	if (args.Length() < 1) {
		char errorStringBuffer[100];
		sprintf(errorStringBuffer, "getSensorInfos: Invalid number of arguments. Expected 1 but got %d", args.Length());
		return ThrowException(Exception::Error(String::New(errorStringBuffer)));
	}

	jvalue jArguments[1];




	
	
		if ((titanium::V8Util::isNaN(args[0]) && !args[0]->IsUndefined()) || args[0]->ToString()->Length() == 0) {
			const char *error = "Invalid value, expected type Number.";
			LOGE(TAG, error);
			return titanium::JSException::Error(error);
		}
	if (!args[0]->IsNull()) {
		Local<Number> arg_0 = args[0]->ToNumber();
		jArguments[0].i =
			titanium::TypeConverter::jsNumberToJavaInt(env, arg_0);
	} else {
		jArguments[0].i = NULL;
	}

	jobject javaProxy = proxy->getJavaObject();
	jobject jResult = (jobject)env->CallObjectMethodA(javaProxy, methodID, jArguments);



	if (!JavaObject::useGlobalRefs) {
		env->DeleteLocalRef(javaProxy);
	}



	if (env->ExceptionCheck()) {
		Handle<Value> jsException = titanium::JSException::fromJavaException();
		env->ExceptionClear();
		return jsException;
	}

	if (jResult == NULL) {
		return Null();
	}

	Handle<Value> v8Result = titanium::TypeConverter::javaObjectToJsValue(env, jResult);

	env->DeleteLocalRef(jResult);


	return v8Result;

}
Handle<Value> SensorModule::getSensorInfost(const Arguments& args)
{
	LOGD(TAG, "getSensorInfost()");
	HandleScope scope;

	JNIEnv *env = titanium::JNIScope::getEnv();
	if (!env) {
		return titanium::JSException::GetJNIEnvironmentError();
	}
	static jmethodID methodID = NULL;
	if (!methodID) {
		methodID = env->GetMethodID(SensorModule::javaClass, "getSensorInfost", "(I)Lorg/appcelerator/kroll/KrollDict;");
		if (!methodID) {
			const char *error = "Couldn't find proxy method 'getSensorInfost' with signature '(I)Lorg/appcelerator/kroll/KrollDict;'";
			LOGE(TAG, error);
				return titanium::JSException::Error(error);
		}
	}

	titanium::Proxy* proxy = titanium::Proxy::unwrap(args.Holder());

	if (args.Length() < 1) {
		char errorStringBuffer[100];
		sprintf(errorStringBuffer, "getSensorInfost: Invalid number of arguments. Expected 1 but got %d", args.Length());
		return ThrowException(Exception::Error(String::New(errorStringBuffer)));
	}

	jvalue jArguments[1];




	
	
		if ((titanium::V8Util::isNaN(args[0]) && !args[0]->IsUndefined()) || args[0]->ToString()->Length() == 0) {
			const char *error = "Invalid value, expected type Number.";
			LOGE(TAG, error);
			return titanium::JSException::Error(error);
		}
	if (!args[0]->IsNull()) {
		Local<Number> arg_0 = args[0]->ToNumber();
		jArguments[0].i =
			titanium::TypeConverter::jsNumberToJavaInt(env, arg_0);
	} else {
		jArguments[0].i = NULL;
	}

	jobject javaProxy = proxy->getJavaObject();
	jobject jResult = (jobject)env->CallObjectMethodA(javaProxy, methodID, jArguments);



	if (!JavaObject::useGlobalRefs) {
		env->DeleteLocalRef(javaProxy);
	}



	if (env->ExceptionCheck()) {
		Handle<Value> jsException = titanium::JSException::fromJavaException();
		env->ExceptionClear();
		return jsException;
	}

	if (jResult == NULL) {
		return Null();
	}

	Handle<Value> v8Result = titanium::TypeConverter::javaObjectToJsValue(env, jResult);

	env->DeleteLocalRef(jResult);


	return v8Result;

}
Handle<Value> SensorModule::setSensor(const Arguments& args)
{
	LOGD(TAG, "setSensor()");
	HandleScope scope;

	JNIEnv *env = titanium::JNIScope::getEnv();
	if (!env) {
		return titanium::JSException::GetJNIEnvironmentError();
	}
	static jmethodID methodID = NULL;
	if (!methodID) {
		methodID = env->GetMethodID(SensorModule::javaClass, "setSensor", "(I)V");
		if (!methodID) {
			const char *error = "Couldn't find proxy method 'setSensor' with signature '(I)V'";
			LOGE(TAG, error);
				return titanium::JSException::Error(error);
		}
	}

	titanium::Proxy* proxy = titanium::Proxy::unwrap(args.Holder());

	if (args.Length() < 1) {
		char errorStringBuffer[100];
		sprintf(errorStringBuffer, "setSensor: Invalid number of arguments. Expected 1 but got %d", args.Length());
		return ThrowException(Exception::Error(String::New(errorStringBuffer)));
	}

	jvalue jArguments[1];




	
	
		if ((titanium::V8Util::isNaN(args[0]) && !args[0]->IsUndefined()) || args[0]->ToString()->Length() == 0) {
			const char *error = "Invalid value, expected type Number.";
			LOGE(TAG, error);
			return titanium::JSException::Error(error);
		}
	if (!args[0]->IsNull()) {
		Local<Number> arg_0 = args[0]->ToNumber();
		jArguments[0].i =
			titanium::TypeConverter::jsNumberToJavaInt(env, arg_0);
	} else {
		jArguments[0].i = NULL;
	}

	jobject javaProxy = proxy->getJavaObject();
	env->CallVoidMethodA(javaProxy, methodID, jArguments);

	if (!JavaObject::useGlobalRefs) {
		env->DeleteLocalRef(javaProxy);
	}



	if (env->ExceptionCheck()) {
		titanium::JSException::fromJavaException();
		env->ExceptionClear();
	}




	return v8::Undefined();

}

// Dynamic property accessors -------------------------------------------------


void SensorModule::setter_sensor(Local<String> property, Local<Value> value, const AccessorInfo& info)
{
	LOGD(TAG, "set sensor");
	HandleScope scope;

	JNIEnv *env = titanium::JNIScope::getEnv();
	if (!env) {
		LOGE(TAG, "Failed to get environment, sensor wasn't set");
		return;
	}

	static jmethodID methodID = NULL;
	if (!methodID) {
		methodID = env->GetMethodID(SensorModule::javaClass, "setSensor", "(I)V");
		if (!methodID) {
			const char *error = "Couldn't find proxy method 'setSensor' with signature '(I)V'";
			LOGE(TAG, error);
		}
	}

	titanium::Proxy* proxy = titanium::Proxy::unwrap(info.Holder());
	if (!proxy) {
		return;
	}

	jvalue jArguments[1];

	
	
		if ((titanium::V8Util::isNaN(value) && !value->IsUndefined()) || value->ToString()->Length() == 0) {
			const char *error = "Invalid value, expected type Number.";
			LOGE(TAG, error);
		}
	if (!value->IsNull()) {
		Local<Number> arg_0 = value->ToNumber();
		jArguments[0].i =
			titanium::TypeConverter::jsNumberToJavaInt(env, arg_0);
	} else {
		jArguments[0].i = NULL;
	}

	jobject javaProxy = proxy->getJavaObject();
	env->CallVoidMethodA(javaProxy, methodID, jArguments);

	if (!JavaObject::useGlobalRefs) {
		env->DeleteLocalRef(javaProxy);
	}



	if (env->ExceptionCheck()) {
		titanium::JSException::fromJavaException();
		env->ExceptionClear();
	}




	Proxy::setProperty(property, value, info);
}



void SensorModule::setter_sensorList(Local<String> property, Local<Value> value, const AccessorInfo& info)
{
	LOGD(TAG, "set sensorList");
	HandleScope scope;

	JNIEnv *env = titanium::JNIScope::getEnv();
	if (!env) {
		LOGE(TAG, "Failed to get environment, sensorList wasn't set");
		return;
	}

	static jmethodID methodID = NULL;
	if (!methodID) {
		methodID = env->GetMethodID(SensorModule::javaClass, "getSensorList", "(I)[I");
		if (!methodID) {
			const char *error = "Couldn't find proxy method 'getSensorList' with signature '(I)[I'";
			LOGE(TAG, error);
		}
	}

	titanium::Proxy* proxy = titanium::Proxy::unwrap(info.Holder());
	if (!proxy) {
		return;
	}

	jvalue jArguments[1];

	
	
		if ((titanium::V8Util::isNaN(value) && !value->IsUndefined()) || value->ToString()->Length() == 0) {
			const char *error = "Invalid value, expected type Number.";
			LOGE(TAG, error);
		}
	if (!value->IsNull()) {
		Local<Number> arg_0 = value->ToNumber();
		jArguments[0].i =
			titanium::TypeConverter::jsNumberToJavaInt(env, arg_0);
	} else {
		jArguments[0].i = NULL;
	}

	jobject javaProxy = proxy->getJavaObject();
	env->CallObjectMethodA(javaProxy, methodID, jArguments);

	if (!JavaObject::useGlobalRefs) {
		env->DeleteLocalRef(javaProxy);
	}



	if (env->ExceptionCheck()) {
		titanium::JSException::fromJavaException();
		env->ExceptionClear();
	}




	Proxy::setProperty(property, value, info);
}



void SensorModule::setter_enableSensor(Local<String> property, Local<Value> value, const AccessorInfo& info)
{
	LOGD(TAG, "set enableSensor");
	HandleScope scope;

	JNIEnv *env = titanium::JNIScope::getEnv();
	if (!env) {
		LOGE(TAG, "Failed to get environment, enableSensor wasn't set");
		return;
	}

	static jmethodID methodID = NULL;
	if (!methodID) {
		methodID = env->GetMethodID(SensorModule::javaClass, "enableSensor", "(Ljava/lang/String;)V");
		if (!methodID) {
			const char *error = "Couldn't find proxy method 'enableSensor' with signature '(Ljava/lang/String;)V'";
			LOGE(TAG, error);
		}
	}

	titanium::Proxy* proxy = titanium::Proxy::unwrap(info.Holder());
	if (!proxy) {
		return;
	}

	jvalue jArguments[1];

	
	
	if (!value->IsNull()) {
		Local<Value> arg_0 = value;
		jArguments[0].l =
			titanium::TypeConverter::jsValueToJavaString(env, arg_0);
	} else {
		jArguments[0].l = NULL;
	}

	jobject javaProxy = proxy->getJavaObject();
	env->CallVoidMethodA(javaProxy, methodID, jArguments);

	if (!JavaObject::useGlobalRefs) {
		env->DeleteLocalRef(javaProxy);
	}



				env->DeleteLocalRef(jArguments[0].l);


	if (env->ExceptionCheck()) {
		titanium::JSException::fromJavaException();
		env->ExceptionClear();
	}




	Proxy::setProperty(property, value, info);
}



void SensorModule::setter_sensorInfos(Local<String> property, Local<Value> value, const AccessorInfo& info)
{
	LOGD(TAG, "set sensorInfos");
	HandleScope scope;

	JNIEnv *env = titanium::JNIScope::getEnv();
	if (!env) {
		LOGE(TAG, "Failed to get environment, sensorInfos wasn't set");
		return;
	}

	static jmethodID methodID = NULL;
	if (!methodID) {
		methodID = env->GetMethodID(SensorModule::javaClass, "getSensorInfos", "(I)Lorg/appcelerator/kroll/KrollDict;");
		if (!methodID) {
			const char *error = "Couldn't find proxy method 'getSensorInfos' with signature '(I)Lorg/appcelerator/kroll/KrollDict;'";
			LOGE(TAG, error);
		}
	}

	titanium::Proxy* proxy = titanium::Proxy::unwrap(info.Holder());
	if (!proxy) {
		return;
	}

	jvalue jArguments[1];

	
	
		if ((titanium::V8Util::isNaN(value) && !value->IsUndefined()) || value->ToString()->Length() == 0) {
			const char *error = "Invalid value, expected type Number.";
			LOGE(TAG, error);
		}
	if (!value->IsNull()) {
		Local<Number> arg_0 = value->ToNumber();
		jArguments[0].i =
			titanium::TypeConverter::jsNumberToJavaInt(env, arg_0);
	} else {
		jArguments[0].i = NULL;
	}

	jobject javaProxy = proxy->getJavaObject();
	env->CallObjectMethodA(javaProxy, methodID, jArguments);

	if (!JavaObject::useGlobalRefs) {
		env->DeleteLocalRef(javaProxy);
	}



	if (env->ExceptionCheck()) {
		titanium::JSException::fromJavaException();
		env->ExceptionClear();
	}




	Proxy::setProperty(property, value, info);
}



void SensorModule::setter_sensorInfost(Local<String> property, Local<Value> value, const AccessorInfo& info)
{
	LOGD(TAG, "set sensorInfost");
	HandleScope scope;

	JNIEnv *env = titanium::JNIScope::getEnv();
	if (!env) {
		LOGE(TAG, "Failed to get environment, sensorInfost wasn't set");
		return;
	}

	static jmethodID methodID = NULL;
	if (!methodID) {
		methodID = env->GetMethodID(SensorModule::javaClass, "getSensorInfost", "(I)Lorg/appcelerator/kroll/KrollDict;");
		if (!methodID) {
			const char *error = "Couldn't find proxy method 'getSensorInfost' with signature '(I)Lorg/appcelerator/kroll/KrollDict;'";
			LOGE(TAG, error);
		}
	}

	titanium::Proxy* proxy = titanium::Proxy::unwrap(info.Holder());
	if (!proxy) {
		return;
	}

	jvalue jArguments[1];

	
	
		if ((titanium::V8Util::isNaN(value) && !value->IsUndefined()) || value->ToString()->Length() == 0) {
			const char *error = "Invalid value, expected type Number.";
			LOGE(TAG, error);
		}
	if (!value->IsNull()) {
		Local<Number> arg_0 = value->ToNumber();
		jArguments[0].i =
			titanium::TypeConverter::jsNumberToJavaInt(env, arg_0);
	} else {
		jArguments[0].i = NULL;
	}

	jobject javaProxy = proxy->getJavaObject();
	env->CallObjectMethodA(javaProxy, methodID, jArguments);

	if (!JavaObject::useGlobalRefs) {
		env->DeleteLocalRef(javaProxy);
	}



	if (env->ExceptionCheck()) {
		titanium::JSException::fromJavaException();
		env->ExceptionClear();
	}




	Proxy::setProperty(property, value, info);
}



		} // sensor
		} // geraudbourdin
		} // com
