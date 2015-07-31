﻿// Copyright © 2010-2015 The CefSharp Project. All rights reserved.
//
// Use of this source code is governed by a BSD-style license that can be found in the LICENSE file.
#pragma once

#include "Stdafx.h"

#include "JavascriptMethodWrapper.h"

using namespace System;

namespace CefSharp
{
    void JavascriptMethodWrapper::Bind(const CefRefPtr<CefV8Value>& v8Value)
    {
        auto methodName = StringUtils::ToNative(_javascriptMethod->JavascriptName);
        auto v8Function = CefV8Value::CreateFunction(methodName, _javascriptMethodHandler.get());

        v8Value->SetValue(methodName, v8Function, V8_PROPERTY_ATTRIBUTE_NONE);
    };

    BrowserProcessResponse^ JavascriptMethodWrapper::Execute(array<Object^>^ parameters)
    {
        return _browserProcess->CallMethod(_ownerId, _javascriptMethod->JavascriptName, parameters);
    }
}