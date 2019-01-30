Inline member functions, Constructors, Destructors, Private member functions

// ^ definition: We can put the code for a function or a class member inside the class instead of separately

    class Student
    {
        ...
        int getID()
        {
            return id;
        }
    }

    inline functions replace it with the code rather than calling that function
    
    // inline functions are to be used only when the definition is really short
    
    // When you have an inline function, you dont need scope resolution operator.

    Constructors - a function that a class uses to initialize class members variables and 
    any other setup that is required.

    A constructor has the same name as the class and is called automatically when the class
    is created in memory. this happens when:

        - new operator

        - declare an instance

        - it does not happen when we declare a pointer


    class Student
    {
        public: // we have to make it public
            Student(); // no return type specified
        ...
    };

    Student::Student()
    {
        ...
    } // no return type because it is return its own class

// You should consider writing a constructor for every class.

// Constructors can have arguements passed as parameters. if a constructor has no arguements, 
// it is considered the "default constructor"

// We can have multiple constructors as well. A default is not required and if there is a 
// constructor a default one will not be supplied.


    class Student
    {
        public: // we have to make it public
            Student(string name); // no return type specified
            Student(string name, int MNumber);
        ...
    };

    Student::Student(string name)
    {
        ...
    }


// Checkpoint

    // 13.6 - So they cant be changed by the user.  can make sure values assigned are appropriate and legal

    // 13.7 - setters and getters

    // 13.8 - specification is the .h and the implementation is the .cpp file.

    // 13.9 - keeps us from declaring something twice #ifndef

    // 13.10 - 
                BasePay Declaration - BasePay.h
                BasePay member fuction definitions - BasePay.cpp

    // 13.11 - when you write the code for a class member function in the class declaration



// Passing arguments to the constructor.

    int i;
    Student Sam("Samantha");
    Student s = new Student("Billy");

    class Student
    {
        public: // we have to make it public
            Student(string name); // no return type specified
            Student(string name, int MNumber);
        ...
    };

    Student::Student(string name) // constructor
    {
        me.Student(name, 123456);
    }

    Student::Student(string name)
    {
        ...
    }


// We can still have default arguments in constructors.
// If we have a constructor that looks like:

        Student::Student(string name="No Name Given", int MNumber=12345){}
        // if all parameters are optional, it becomes a default constructor.
        
        Student::Student(){} // This is illegal if the above exist because the compiler wouldnt know which to call.

// If you dont have a default constructor or a constructor with all optional parameters and you 
// try to create an instance with no parameters, it will be a compiler error


// DESTRUCTORS - destructor is like a constructor expect it is called when an object is removed from memory (destroyed)

    // destructors are called automatically. they give you a chance to cleanup such as closing files or DB connections or 
    // freeing memory used inside the class.

    // destructors have the same name as the class except they have the ~ prefix

    class Student
    {
        public:
            ~Student();
        ...
    };


// Checkpoint 

// 13.12 - allocates memory for a class object. Gets a class ready to be used.

// 13.13 - removes class object from memory. 

// 13.14 - A

// 13.15 - B

// 13.16 - B

// 13.17 - A



// Private member functions
    
    // Private member functions can only be called from inside the class.
    // These functions can be public or private member functions. These can modify public
    // or private member variables.

    // we can create arrays of objects.
    // when you create an array of objects that are classes, the constructor is called when the array is created.


        Student cs2028C[70]; // the constructor is called 70 times here.

    
    // We can initialize the class instances when we initialize our array.

        // 1 parameter

            Student cs2028C[70] = {"Mary", "Scott", "Patty", ...};

    // OR

        // Multiple parameters

            Student cs2028C[70] = {Student("Bob", 123), Student("Jill", 456), ...};

    
    // To access class members in an array

        cs2028C[3].Name = "Patricia";
        cout << cs2028C[2].MNumber << endl;



// Checkpoint

// 13.21 -  10
//          20
//          50

// 13.22 -  4
//          7
//          2 // trick question destructor is called after program ends
