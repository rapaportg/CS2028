Classes
//Procedural and Object oriented Programming

// Procedural - what we have done up to now. Data and functions are defined separately.

// Object Oriented - based around creating objects that contain both data and procedures

// The data in an object is called attributes. Procedures in an object are called member functions
// Sometimes these are called properties and methods in other languages

// Encapsulation - is combining data and code into a single object

// Data Hiding - hiding attributes that arent exposed to outside functions.
// Only member functions have access to these attributes

// Object reusability - by packaging code into objects, its easier to reuse.

// Class is code that specifies that both attributes and member functions that make up and object. 
// like a struct, you still need to create an instance

    // Classes consist of variables and functions (usually doing operations on those variables)

    class Student
    {
        string name;
        int id;
        string GetName()
        {
            return name;
        }
    };

    // By default all members of a class are hidden. To make them available you need to change the access specifier.
    
        // Access Specifiers

            private // only member functions can access

            protected // member functions. friends, and derived classes can access

            public // if you can accss the instantiated class. you can access these members

    class Student 
    {
        public: 
            string getName();
        private:
            string name;
            void setName(string name);
    };

    // It is not required to group your public and private sections together. But do it, 
    // it makes it easier to read.
    // frequently, attributes will be defined as private to get the value and set the value. 
    // These are called Getters and Setters.

    // Adding the const keyword to the end of a function prototype tells the compiler the 
    // function shouldnt modify member variables.

    // To define member functions outside of the class definition. Do the following:

        string Student::getName()
        {
            return name;
        }
    
    // Defining a class function outside the class declaration isnt required. 
    // My rule of thumb is define it outside if it is more than 5 lines of code.
    // Code defined inside the class is called inline

    // Note, it would be perfectly legal to define getname without the Student:: However 
    // it wouldnt do what you wanted it to.
    // Leaving it off what student:: would create a function that was indepented of the class.

    // The two colons are called the scope resolution operator.

    // To actually use a class, you still need to create an instance of it
        Student sue;

    // Accessing object members of classes is just like accessing object members of structures/

        sue.name = "Susan"; // this would not compile. it would tell you that name is recognized 
                            // because its private

        cout << sue.getName(); // perfectly legal

    // For member functions that use memeber data, its best to refetch it everytime the function 
    // has been called to avoid missing out on updates. This is a concern is you use static variables



// Pointers to classes - pointers to classes work essentially the same as pointers to structures 
    
    // Use the -> operator to access member data/functions

    Student *currStudent = &Sue;
    cout << currStudent -> getName();

    // This is equivalent to

    cout << *(currStudent).getName(); // dot operator overrides dereference operator

// The new operator works with classes the same as structures. so does the delete operator
 
    // new - creates new memory on the heap. Then it returns a pointer to the object/

    // delete - marks the memory for that object as available for use.


// why private members? 
    // allows you to provide data validation.
    // allows us to control the state of our class without worries about someone else modifying


// Typically classes are defined in their own separate files. This is called the "class specification" file.
// typically this file has a .h extension with name the same as class name. Student.h

// Its common to put your class member function's definitions in a separate file from the class 
// specificaton. This is called the "class implementation" file. This typically has a .cpp extenstion
// this .cpp will need to include you .h file

// Any program using the class will include the .h file, not the .cpp file.


// Preprocessor statement
    #ifndef - used to check if a header file has already been included so it doesnt get included twice.

    #ifndef - if not defined. this is an if statement executed by the Preprocessor. it is checking if a variable is defined.

    #define - defines variable

    #endif = end of our if statement.

    

