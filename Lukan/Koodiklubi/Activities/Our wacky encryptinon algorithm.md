- Each one of us makes a encryption method that takes in a string and returns another string.

```C#
public string YourEncryptionFunction(string input)
{

	// Your encryption algorithm here

	return input;
}
```

- You can manipulate the input string how ever you like **as the method is reversable.**

- When the output of the method is reintroduced to the method, it returns the initial input.

- Here's a method that just flips the input. This means that when you for example input a "Horse" in to the method, it returns a "esroH". After that you can input "esroH" and get back "Horse".

```C#
public string ReversingEncryptionFunction(string input)
{
	//Turn string into character array
	char[] charArray = input.ToCharArray(); 
	
	//Reverse the order of characters in the array
	Array.Reverse(charArray);
	
	//Make a new string out of reversed character array
	input = new string(charArray);
	
	return input;
}
```

