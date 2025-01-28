package com.services.impl;

import com.services.HelloWorld;

import jakarta.jws.WebService;

@WebService(endpointInterface = "com.services.HelloWorld")
public class HelloWorldImpl implements HelloWorld {
	@Override
	public String getHelloWorldAsString(String name) {
		return "This is the message from server: " + name;
	}
}
