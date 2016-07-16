// anurocha_node.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"

// hello.cc
#include "include/node/node.h"

namespace demo {

	using v8::FunctionCallbackInfo;
	using v8::Isolate;
	using v8::Local;
	using v8::Object;
	using v8::String;
	using v8::Value;

	void SayHi(const FunctionCallbackInfo<Value>& args) {
		Isolate* isolate = args.GetIsolate();
		args.GetReturnValue().Set(String::NewFromUtf8(isolate, "Hi - How are you doing?"));
	}

	void init(Local<Object> exports) {
		NODE_SET_METHOD(exports, "hello", SayHi);
	}

	NODE_MODULE(addon, init)

}  // namespace demo