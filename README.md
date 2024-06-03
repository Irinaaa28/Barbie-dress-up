# Barbie Dress Up Minigame Concept

## Introduction
I have adopted and implemented the concept of "Barbie Dress Up" games, a very popular game among browser users, which has brought happiness to many girls during their childhood. 
## How does the code behind this minigame look like?
Long story short, I used plenty of classes to distinguish every piece of clothing, to represent the Barbie doll and to face possible errors. Here are the steps:
* I created an interface called "Wardrobe" where to start the whole code;
* I created an abstract class called "Garment", which represents a general piece of clothing. Each variable in the "Garment" class consists of a code and a color; 
* Using the principle of inheritance, I created four derived classes from the "Garment" class, representing different types of clothing: "Blouse", "Dress", "Pants" and "Skirt".
* In order to prevent the game from ending due to an eventual error, I considered and implemented some classes for all possible errors;
* Then, I created a class called "Barbie", which represents the Barbie doll itself. Through the "Barbie" class, we upgrade her physical appearance by repeatedly adding and removing various clothes.
## What do these classes contain?
Within these classes I implemented:
* different void functions for describing, adding and removing clothes
* default constructors
* getters
* setters
* operator=
* copy constructors
* operator<<
* operator>>
* move constructors
* move assignment operators
* destructors.
For the error claases, I only wrote a default constructor where to show the text for every error.
## Is there anything else besides classes in the game?
Of course. I implemented void functions to remove clothes, to change all the letters from a word in small ones and to show Barbie's final look.
## Ok, but how does the main look like?
Firstly, I added default blouses, dresses, skirts and pants which to dress up Barbie with. The main code is a really interactive one, because you can add and remove clothes by your preference. When you decide finishing the game, there will be showed Barbie's final look.
## Ok, but I can see this concept both in project 1 and project 2. Why did you create project 3 with the same concept?
Well, throughout the project, I updated this minigame so that it would be more efficient and contain more and more concepts of OOP. In other words, I improved this minigame to the next level.
Besides the implementation from the other project, I came out with:
* Smart pointers
* Clone() method
* Lambda expressions
* SOLID principle
* design patterns
* templates.
Let me explain in detail why and how I implemented these concepts in project 3.
## Smart pointers
In the provided code for the Barbie class, using smart pointers (std::unique_ptr) improve memory management and code safety significantly. Replacing raw pointers with smart pointers brings the following benefits:
* Elimination of memory leaks: In case of exceptions or improper memory handling, std::unique_ptr ensures automatic memory release when objects go out of scope.
* Increased safety: Raw pointers can lead to memory management issues such as memory leaks or double-deletes. Using std::unique_ptr ensures correct management of each object's memory.
* Cleaner and more understandable code: Using smart pointers makes the code clearer and easier to understand, as it clearly expresses the programmer's intention regarding object ownership and lifetime.
## Clone() method
In the given code, the clone() method is improved by using smart pointers (std::unique_ptr) instead of raw pointers. This enhancement offers several advantages:
* Memory Management: Smart pointers automatically manage memory, ensuring that cloned objects are properly allocated and deallocated when they go out of scope. This eliminates the risk of memory leaks.
* Safety: Using std::unique_ptr ensures that only one instance of the cloned object exists at any given time, preventing issues like double deletion or memory corruption.
* Readability and Maintainability: Code using smart pointers is generally more readable and easier to maintain. It clearly indicates ownership semantics and simplifies understanding of object lifetimes and responsibilities.
## Lambda expressions
Lambda expressions are used here to create a simple, specific, and inline function necessary for finding and removing an object of a specific type from a vector of smart pointers. They bring significant advantages in terms of code clarity and efficiency, avoiding the need to define a separate function in this straightforward and specific context.
