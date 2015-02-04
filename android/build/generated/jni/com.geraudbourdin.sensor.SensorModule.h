/**
 * Appcelerator Titanium Mobile
 * Copyright (c) 2011-2013 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License
 * Please see the LICENSE included with this distribution for details.
 */

/** This is generated, do not edit by hand. **/

#include <jni.h>

#include "Proxy.h"

		namespace com {
		namespace geraudbourdin {
		namespace sensor {


class SensorModule : public titanium::Proxy
{
public:
	explicit SensorModule(jobject javaObject);

	static void bindProxy(v8::Handle<v8::Object> exports);
	static v8::Handle<v8::FunctionTemplate> getProxyTemplate();
	static void dispose();

	static v8::Persistent<v8::FunctionTemplate> proxyTemplate;
	static jclass javaClass;

private:
	// Methods -----------------------------------------------------------
	static v8::Handle<v8::Value> getSensorList(const v8::Arguments&);
	static v8::Handle<v8::Value> enableSensor(const v8::Arguments&);
	static v8::Handle<v8::Value> listSensor(const v8::Arguments&);
	static v8::Handle<v8::Value> getListSensor(const v8::Arguments&);
	static v8::Handle<v8::Value> getSensorInfos(const v8::Arguments&);
	static v8::Handle<v8::Value> getSensorInfost(const v8::Arguments&);
	static v8::Handle<v8::Value> setSensor(const v8::Arguments&);

	// Dynamic property accessors ----------------------------------------
	static void setter_sensor(v8::Local<v8::String> property, v8::Local<v8::Value> value, const v8::AccessorInfo& info);
	static void setter_sensorList(v8::Local<v8::String> property, v8::Local<v8::Value> value, const v8::AccessorInfo& info);
	static void setter_enableSensor(v8::Local<v8::String> property, v8::Local<v8::Value> value, const v8::AccessorInfo& info);
	static void setter_sensorInfos(v8::Local<v8::String> property, v8::Local<v8::Value> value, const v8::AccessorInfo& info);
	static void setter_sensorInfost(v8::Local<v8::String> property, v8::Local<v8::Value> value, const v8::AccessorInfo& info);

};

		} // sensor
		} // geraudbourdin
		} // com
