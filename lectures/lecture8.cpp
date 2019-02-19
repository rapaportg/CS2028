Polymorphism and virtual member functions

    // Polymorphism allows  an object reference variable or object to reference other objects of different types and to call the correct memeber functions, depending on the type of object being 
    // referenced

    // Static Binding = proccess of matching a fucntion call with a function at compile time


    // A dog inherits from an animal and overrides the move function 

    // A function createed that uses animal as a parameter and calls move.
    
    //if we pass an instance of a dog to that function, This will call the animal version of move rather than the dog version because dog overrode move

    //to fix
        
        //Dynamic binding - determining at runtime which function to call based on the type of object making the call rather than the declared type 


    
    //To tell the compiler a classes member should use dynamic binding, used virtual


        virtual returnType MethodName(param); 

            //Virtual keyword goes in the (.h) not in the (.cpp)




    // Polymorphism means the ability to take many forms


    
    // A base class pointer can point at any derived type from that base class.


            BaseClass *parent = new DerivedClass();

    
    // When you do this, the base class instance will only have access to the member from the base class.
    // Members of the derived class will not be available.


    // Redefining vs. Overriding - frequently used interchangably. (incorrectly)

        Redefining = static binding

        Overriding = dynamic binding


// Abstract base classes and pure virtual functions

    // An Abstract base class cannot be instantiated. it requires that other classes derive
    // from it.

    // A pure virtual function is a virtual member function of a base class that must be overridden

    // When a class contains a pure virtual function as a member, that the class becomes an 
    // abstract base class.

      //  Syntax:

                virtual returnType FunctionName(Params) = 0;


    //When a class contains a pure virtual function, it becomes abstract.


    //when deriving from an abstract class, all pure virtual functions must be overridden
    //or the derived class is also an abstract class.



// 15.9 - Redefing is static and overloading is dynamic

// 15.10 - static will always call that types member where dynamic may call a derived type's member

// 15.11 - dynamic

// 15.12 - 1
//         5

// 15.13 - 2
//         2

// 15.14 - 2
//         1




// Multiple inheritance is deriving from a class from 2 or more base classes.

    // Syntax
    
        class DerivedClassName: AcessSpecifier BaseClassName1, AcessSpecifier BaseClassName2{...}


    // for constructors:

        DerivedClassName::DerivedClassName(params):BaseClassName1(params), BaseClassName2(param);

        // if both base classes have a member with the same name the derived class should redefine or override those members.



// Checkpoint page 975

// 15.16 - chain

// 15.17 - multiple



// Exceptions - Used to signal an unexpected event that occurered while running

    //Examples:

        // Divided by Zero

        // Wrong Data Type

        // File I/O Errors 

        // Out of memory (new operator)



    // To handle an Exception, we use a try catch block.

        try
        {

            // Code that may throw and exception

        }
        catch(ExceptionParameters)// ExceptionParameters are optional
        {  

            // Code that handles exception
        }

    // Catch blocks can be repeated for a single try block. This allows you to catch and handle different errors differently.


    // The exception parameter of the catch block specifies what type of exception and allows you to name it
    // so you can do something like it log the number and/or the message.
    

    // If no error occurs when the try block completes, all catch blocks are skipped.

    // When we execute our code, if an error occurs inside the try block, it immediately stops execution
    // it then proceeds to find a catch block with matching parameters

    // if an exception is not handled, it will cause the program to abort.
    // an exception is unhandled if:

        // it occurs outside of a try block

        // it occurs inside a try block but there is not an appropriate catch block.

    
    // you can also throw an exception yourself

        throw argument; // argument can be any type. (usually string or exception)

    // when a throw is executed, control is passes to an exception handler. if a throw occurs in a function (other than main), 
    // that function is aborted unless inside of a try/catch block.



    // You can also create you own custon error classes

    // you can add value to the exception object before throwing it. then you can read those values in the catch block
    
    
    // Unwinding the stack - if an exception is unhandled in a function, it returns (aborts) to where
    // it was called and looks for a catch. Any item with scope of the try block are lost when exception occurs


    // you can also rethrow and exception

        try
        {
            ...
        }
        catch(exception err)
        {
            throw; // this will rethrow the error
        }



    // Best practices for exceptions

        // Dont swallow exceptions - if you cant handle it gracefully, rethrow it.

        // Dont use an exception if you can check a condition first. (like if the value is < 0 in main rather than using a try again loop)

        // Dont use Exceptions for fequently occuring events.

        // Keep the code in the try block as short as possible.

        // order catch block exceptions from most specific to least specific.

        // Throw exceptions instead of returning error codes.

        // End exception class names with the name exception. Ex: NegativeWidthException.

        
