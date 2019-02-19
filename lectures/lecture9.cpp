Class templates are similiar to function templates. The template used is to determine the type of class member


// Syntax:

        template<class T>

        class myClass
        {
            private:
                T myData;

            public:
                T getMyData(){return myData;}
                void setMyData(T val){myData = val;}
        };


// To create an instance of this class:
    
    myClass<int> num;
    num.SetMyData(10);

    myClass<double> vals;
    vals.SetMyData(100.32);


// You can inhereit from a template class. Either the derived class must specify the type for the base class.
// or the derived class must specify the type to the base class


// Specialized  templates are used for specific exceptions to templates. instead of specifying the type as generic.
// specify the type specifically

    template<>
    class myClass<string>
    {
        ... // All types here must be specific
    }



// Checkpoint pg.1023

// 16.10 - list<int> l;

// 16.11 - 





// Introductions to the STL

    // STL = Standard Template Library
        // contains many templates for useful algorithms and data structures. this is kind of a very early version
        // of Java and C# libs

    // contains Abstract data types like:

        // Vector - an improved array that shrinks and grows. 

        // Dequeuer - double ended queue that can shrink or grow from both sides.

        // List - Double link list

        // Forward_list - single link list

        // Associative:

            // Set - a set of keys and the keys must be unique

            // Multiset - a set of keys and the keys do not have to be unique

            // Map - A key/Value pair (python calls it dictionary). Keys must be unique

            // Mulitmap - same as map except keys dont have to be unique
            
        // there are a number of algorthrims that support these containers <algorithm>

            // Max_element

            // Min_element

            // For_each

            // Find_if

            // Sort


