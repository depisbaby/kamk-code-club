**Why we use pointers**
 The existence of pointers in C++ come partly from the fact the we, developers need to manage the memory ourselves. In C# and JavaScript such pointers are not needed as much thanks to the implemented garbage collector. There are other advantages to using pointers of which we'll look at later.

**Pointers**

 Let's start by creating a house. When we do that the house is created in the memory (in this case in stack memory). This means in it's essence that now there is a long row of 0s and 1s that makes up the house. The more complex the class House is the bigger chunk of memory it takes up.
 
```C++
House house; //Create a new house in stack memory
```

 In many scenarios it's relevant for us to know where the object is stored in memory. That's why we have pointers. Let's make a pointer that points to the "house".

```C++
House house; //Create a new house in stack memory

House* pHouse = &house; //Create a pointer called "pHouse" and make it point to "house" we created prior to that.
```

 The " * " right after the type indicates that we want to create a pointer of that type. The "&" in front of "house" means that we are referring to the memory address of "house".  Addresses can be assigned to pointers to make them point to that object and that's what we're doing here.
 
 So now we have created a house and a pointer to that house in memory. Having the address to an object is really useful in many scenarios.

![[adas.png]]

**Dereferencing**

 We can easily access the actual value of a object using the pointer that is pointing to it. This is called dereferencing. Here's an example of it in action:
 
```C++
House house; //Make two houses
House otherHouse;

House* pHouse = &house; //Make a pointer "pHouse" that points to "house"

otherHouse = *pHouse; //Turn "otherHouse" into a copy of "house" using the pointer

```

" * " in front of the "pHouse" means that we are not refering to the pointer but rather the value the pointer is pointing to.

But why don't we do it like this?:

```C++
House house; //Make two houses
House otherHouse;

otherHouse = house; //Turn "otherHouse" into a copy of "house"
```

This accomplishes the same thing without any pointers. Here's where concepts like "pass-by-value" and "pass-by-pointer" come in.

**Pass by value**

 When you have a method that takes in a value it copies the value in the scope of that method.
```C++
void Method(int input)
{
 
}

int main //Code starts
{

int x = 5; //Make integer "x" which value is 5

Method(x); //Pass x to "Method()" by value

}
```

 While we are in "Method()" we have 2 integers in stack memory: "int x" and "int input". This might in some cases be redundant. This also means that changing the value of "input" doesn't affect the "x". 

 Here's other example but with more complex object.

```C++
ReallyBigObject Method(ReallyBigObject input)
{
	//Here we have two instances of the really big object in stack
	
	return input;
}

int main //Code starts
{

ReallyBigObject obj; //Make a object "obj" which is really big in terms of memory space

obj = Method(obj); //Pass obj to "Method()" by value

}
```

 It's up to us if we want to pass by value or not. Usually it depends on the situation.

**Pass-by-pointer**

One thing to note is that some objects might take a lot of space in memory while pointers are really small. Let's do the same example but this time we will pass in a pointer instead of the value:

```C++
void Method(ReallyBigObject* input)
{
	//Here we have only one instance of the really big object and a pointer on the stack. 
	

	//If you dereference "input" you get the value "obj"
}

int main //Code starts
{

ReallyBigObject obj;//Make a object "obj" which is really big in terms of memory space

ReallyBigObject* pObj = &obj; //Make a pointer that points to the really big object.

Method(pObj); //Pass the pointer as vaule

}
```

The pointer pObj is passed and copied inside the "Method()" as "input". See how we didn't copy the instance of the really big object but rather the pointer that points to it.

Right now both of the pointers ("pObj" and "input") point to same object. Having just one instance of some really big object in take up less space in memory!

*To recap*

Pass-By-Value
 - Creates a copy of the actual value which might take a lot of memory space
 - Changes made to copied value doesn't affect the original value

Pass-By-Pointer
 - Only the pointer is copied and both of the pointers point to same object.
 - You are making changes to only one instance.

**Accessing members**

 When accessing the members of an object we use "."
 ```C++
 myClass.myOtherClass.name = "Name" //Object "myClass"
```

 But when we want to access members of an object through pointers we use "->"
 ```C++
 pMyClass->myOtherClass->name = "Name" //Pointer to an object "myClass"
```


Miten visuaalisoidaan muistiosoitteet vs?
Pass by ref?
Mistä tietää mitkä kaikki pointterit osoittavat objektiin?
Onko pointterit kaikki saman kokoisia?

 