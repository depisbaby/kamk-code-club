
**Stack memory**
 Stack memory is pretty straight forward. The variables "integer" and "string" and class instance "otherClass" are stored in stack memory. This means that they are usable only inside the "SomeMethod".
 
 ```C++
 SomeClass::SomeMethod()
 {
	int integer = 4;
	std::string string = "bruh";
	OtherClass otherClass(42);
	
	//Can use here
	
 }

//No can use here
```

 Things stored in stack memory are automatically deleted from the memory and therefore you don't need to manage them.

**Limitations of the stack**

 But what if you need to be able to access some of those things outside of the method. Let's say we have a method that can build a house. We would probably like to access that house later in the program.

```C++
SomeClass::BuildAHouse()
{
	House house(); //Build house

	//House exist
	
}//Destroy house

//House no exist
```

Or what if we want to make new houses during the program. Defining number of houses at the beginning of the program locks us to that number of houses.

```C++
int main(){

House house1; //Build houses
House house2;
House house3;


//Program go brrrr

//Oh noooo we need more than three houses, god I wish there was a way to make new houses dynamically!

}
```
 
**Heap heap hooray**

 Dynamic data structures like linked lists depend on the existence of heap memory. We might not know how many things we are creating so the list needs to shrink and expand as needed.
 
![[dfgdfgdfg.png]]

 Let's see the house builder method again but this time we are creating the house using "new" keyword.

 ```C++
SomeClass::BuildAHouse()
{
	House* pHouse = new House(); //Build a house in heap memory and store it's memory address to pointer "pHouse"
	
	//House exist
	
}

//House still exist 
```

When we create a new instance of a object using the "new" we are creating it in heap memory. **We need to immediately assign a pointer to this object to keep track of it's whereabouts in the heap**




