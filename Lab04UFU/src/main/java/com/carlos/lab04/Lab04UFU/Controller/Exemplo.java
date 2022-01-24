package com.carlos.lab04.Lab04UFU.Controller;

public class Exemplo {
	
	String name;
	String age;
	
	public String getName() {
		return name;
	}
	
	public void setName(String name) {
		this.name = name;
	}
	
	public String getAge() {
		return age;
	}
	
	public void setAge(String age) {
		this.age = age;
	}
	
	@Override
	public String toString() {
		return "Nome: " + getName() + "Idade: " + getAge();
	}
}
