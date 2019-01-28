Files
//  To work with files in c++, we use the header file
    #include <fstream>

// Data types are 
    
    ifstream - read only

    ofstream - write only

    fstream - read and write

    // Way to declare

        fstream data;
        data.open("info", ios::app); // info it the name of the file. ios::app is the mode for that file pg.658

        // File Access Flag Meaning
        
        //ios::app Append mode. 
            If the file already exists, its contents are preserved and all
            output is written to the end of the file. By default, this flag causes the file to
            be created if it does not exist.

        //ios::ate 
            If the file already exists, the program goes directly to the end of it. Output
            may be written anywhere in the file.

        //ios::binary Binary mode. 
            When a file is opened in binary mode, data are written to or
            read from it in pure binary format. (The default mode is text.)

        //ios::in Input mode. 
            Data will be read from the file. If the file does not exist, it will
            not be created and the open function will fail.

        //ios::out Output mode. 
            Data will be written to the file. By default, the file’s contents
            will be deleted if it already exists.

        //ios::trunc 
            If the file already exists, its contents will be deleted (truncated). This is the
            default mode used by ios::out. 


    You can use multiple flags at the same time. The way to do this is to use a pipe.

        data.open("info", ios::in | ios::out);

// The file is located in the same folder as the source file you are debugging or in the same folder as you are running the program in.
// if you want a different folder, you need to include the path in the open command.

// To write to the file, you use the << the same as you would to write to terminal

// to check if a file exist, you can open it
    data.open("File", ios::in);
// then check the fail method   
    if (data.fail())
            //no file
    else
        // file Yeah!!


// To read a line from file, use the >>

    string line;
    data >> line; // reads until a whitespace or newline character

// Anything you can do with cout works with fstream with formatting

// We can pass file stream objects to functions.
// you should always pass them by reference

    void getNextLine(fstream &f);

// Detailed error testing 
        
        All file streams have a set of bits maintained internally
        can use these to test fstream functions

// Fstream member functions

    getline - fetches a full line until you get to the end of the line

    get - gets a single character

    put - writes a single character

// Working with multiple files 
    // you can define multiple stream objects to open more than 1 file at a time.

    ifstream myInput;
    ofstream myOutput;
    myInput.open("inputfile.txt", ios::in);
    myOutput.open("outputfile.txt", ios::out);


// Binary files

    Using the flag ios::binary opens a file instead of ASCII

    When opened as binary, you use the .read and .write member functions.
    these functions expect to write the char data type

    .write() - 2 parameters

        Address - this is the memory address you want to write to the file.
        Size - number of bytes you are writing.

    .read() - 2 parameters

        Address - memory location you want to save the data to.
        Size - number of bytes you are writing. Use sizeof() function to determine the number of bytes.


// When we write other data types (no char), we need to type cast them

    File.read(reinterpret_cast<char*>(&x), sizeof(x)); // This will read the value from the file and store it in x.

    File.write(reinterpret_cast<char*>(&x), sizeof(x));


// When you write structures or classes to a file, and pointer addresses become invaild.

    To save stuff in structures and classes to a file, store the members 1 at a time.


// we can also access files randomly - 
        //this means we can access and byte at anytime without regards to what we have previously done

        seekp - seek "put" used to write.

        seekg - seek "get" used to read.

        // seekp and seekg move the stream to a particular byte. they dont actually read or write the data.

            // Arguments

                offset - this the a long integer telling how far in bytes and which direction to move.
                            
                            - positive it forward
                            
                            - negative is backward
                
                Mode flag - tells us what to do with that offset

        // When you are done you should test to see if you have moved past the beginning or end of file.

            // Note: different compilers treat EOF differently so be safe, call .clear() before you seek


        tellp - tell where the cursor is for "putting"

        tellg - tell where the cursor is for "getting"



