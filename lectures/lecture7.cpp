We can redefine a base class fucntion in a derived class. This is commonly called overloading. 

    class Base
    {
        public:
            int A;
            int getA(){return A;}
            void setA(int a){A = a;}


    };

    class Derived
    {
        public:
            int B;
            int getA(){return B;}
            void setA(int a) 
            {
                B = a;
                Base::setA(a); // Calls the base class function
            }
    };


// Pointer Refresher

    // pointers hold addresses rather than data

    * - is called the dereference operator
    & - Address operator
    -> - is used to dereference a variable then use a member of the dereferenced variable

    class Person
    {
        string First, Last;
    }

    Person *P1 = new Person;
    P1->First = "Mary";
    (*P1).First = "Mary";
    *P1.First = "Mary"; //Compile Error. this works if P1 is not a pointer but first is a pointer

    -> : dereferences the object on the left of the arrow.
    * : dereferences the last varible in the chain regardless of it is chained with "." or ->

    // Array of pointers

        string *ptrArray[5];
        ptrArray[0] = new string;
        *ptrArray[0] = "I'm First!";
        cout << ptrArray[0] << endl; // outputs the address of the thing pointed at by the first position 
        cout << ptrArray << endls; // outputs the address of the first item in the array
        cout << *ptrArray[0] << endl; // outputs the value stored. "I'm First!"
