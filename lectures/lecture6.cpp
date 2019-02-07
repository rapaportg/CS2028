Inheritance

// Inheritance allows a new class to be based on existing class. it inherits all members 
//variables and functions (except constructors and destructors) from base class

// Inheritance can be thought of implementing the idea of "is a" relationship

    A smartphone is a computer -> smartphone inherits from computer

    A dog is an animal -> dog inherits from animal


// "Is a" doesnt allows mean there is inheritance

    Julie is a student -> does not mean Julie inherits from student. Instead, Julie is an instance



// How do we know inheritance involves taking an object and adding new details to that object
// (member variables and fucntions)

    smartphone adds a phone number variable to a computer. add a call function to a computer.

// To inherit in c++, Say:

    class derivedClass: accessSpecifier baseClass{...}


// Example:

        class Dog:public Animal{...}


// The access specifier determines how the members of the base class are treated in the derived class. 
// If left off. defaults to private



// Checkpoint

// 15.4 - Protect is visible to inherited classes. private isnt

// 15.5 - class access spec if used with inheritance. member access is for member variables and functions




// Protected members are like private members to instances, but public to derived class members.


// Constructors and destructors with base classes.

    // Constructors are called in order form the lowest base class to highest derived class.


    // Destructors are called in order from highest derived to lowest base class. 


    // You can pass arguements to the base class constructors.

        className::className(ParamList): BaseClassName(ArgList){...};

    
    // If the base class doesnt have a default constructor, you need to call it. if it doesnt, you dont.

        className::className(ParamList){...} // if the base class has a default constructor 