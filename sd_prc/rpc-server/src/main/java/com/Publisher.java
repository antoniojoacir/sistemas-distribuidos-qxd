package com;

import com.services.impl.HelloWorldImpl;

import jakarta.xml.ws.Endpoint;

public class Publisher {

	public static void main(String[] args) {
		Endpoint.publish("http://localhost:8888/rpc/helloworld", new HelloWorldImpl());
	}
}
