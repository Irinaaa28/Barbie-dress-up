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
## SOLID Principle
The SOLID principles are a set of five software design principles aimed at making systems easier to maintain and extend. These principles are:
* Single Responsibility Principle (SRP)
* Open/Closed Principle (OCP)
* Liskov Substitution Principle (LSP)
* Interface Segregation Principle (ISP)
* Dependency Inversion Principle (DIP)
Now, I will argue why my code adheres to each of these principles, or if it does not, why not.
## S - Single Responsibility Principle (SRP)
The Blouse, Dress, Skirt, and Pants classes have a clear responsibility and are responsible for managing their own data and specific operations (e.g., adding and removing garments, describing clothing items, etc.). However, the Barbie class, in the provided code, does not fully adhere to the SRP principle. The SRP suggests that a class should have only one responsibility, meaning it should be responsible for a single aspect of the application. The Barbie class, however, has multiple responsibilities: managing the wardrobe, counting changes and interacting with the user. The Garment and Wardrobe classes in the provided code do adhere to the SRP by having a single, well-defined responsibility and focusing solely on that responsibility without combining other diverse functionalities.
## O - Open/Closed Principle (OCP)
The code allows for extending functionality without modifying existing classes through inheritance and polymorphism. For example, adding a new type of garment (i.e., a new class derived from Garment) does not require changes to the Barbie class.
## L - Liskov Substitution Principle (LSP)
The classes derived from the Garment class (Blouse, Dress, Skirt, and Pants) adhere to the LSP as they behave in a manner consistent with their parent class and do not introduce behaviors that would violate the implicit contract defined by Garment. This contributes to the flexibility and extensibility of the code, facilitating the management of various types of clothing items in the application.
## I - Interface Segregation Principle (ISP)
The Wardrobe interface adheres to the ISP by defining only essential and relevant methods for wardrobe objects without imposing unnecessary or unwanted functionalities. This contributes to a clearer, more modular, and easier-to-maintain system design.
## D - Dependency Inversion Principle (DIP)
The Wardrobe and Garment classes are designed in adherence to the DIP. Wardrobe defines an abstract interface without dependencies on concrete details, and Garment extends this interface by implementing specific functionalities for wardrobe objects without depending on other concrete classes beyond its own requirements. By using interfaces and abstract classes in this way, the code's extensibility and reusability are facilitated, adhering to object-oriented design principles.
## Design Patterns
The code contains the following design patterns: 
* Factory Method Pattern: the addBlouse, addDress, addSkirt, and addPants methods can be seen as factory methods that create specific Garment objects and add them to the list. This pattern allows for the creation of objects without exposing the creation logic to the client and manages instantiation through a common method.
* Prototype Pattern: the clone method in the Garment class is an implementation of the Prototype pattern, which allows for cloning objects without depending on their concrete classes. Each class derived from Garment implements this method to return a copy of itself.
## Templates 
In the given program, templates are used to support the generic functionality of classes and functions, allowing the manipulation and management of different types of objects (in this case, Barbie's garments) in a flexible and efficient manner. Here are some examples of template usage and their explanation in the context of the program:
* Class Templates for Garment and its Subclasses: The Garment class is an abstract class that defines generic behaviors for the garments in Barbie's wardrobe. It uses templates to allow the generic implementation of functions such as clone(), which returns a copy of a Garment object. Subclasses Blouse, Dress, Skirt, and Pants extend the Garment class and override the pure virtual methods to implement behaviors specific to each type of garment.
* Function Templates for the removeGarment() Method: The removeGarment() method is a member function of the Barbie class and is defined as a template function. This allows the template to be used for different types, such as Blouse, Dress, Skirt, or Pants. Inside this template function, lambda expressions are used to search for and remove elements from the garments vector based on the specified type.
Reasons for Using Templates in This Program Include:
* Flexibility and Reusability: Templates allow writing code that can work with different data types without needing code replication. In this case, Garment and its subclasses benefit from the same implementation for certain generic functionalities.
* Efficiency: Using templates eliminates the need to write separate code for each data type with similar behaviors. Thus, the code is more compact and easier to maintain.
* Abstraction: Templates allow writing more abstract code that can be applied in different contexts without significant modifications. In this case, Barbie can manage various types of garments using the same generic removeGarment() method.
In conclusion, using templates in this program improves the flexibility, efficiency, and abstraction of the code, allowing for the effective management and manipulation of various data types, such as the types of garments in Barbie's wardrobe.
