// maxSize is global
class Queue
{
    private:
        int data[maxSize];
        int front = 0; // first item
        int back = -1; //
        int len = 0;

    public:

        void enquene(int inVal)
        {
            if (isFull())
                throw OverFlow; // needs to be defined
            len++;
            back = (back + 1) % maxSize;
            data[back] = inVal;
        }

        int dequeue()
        {
            int outVal = data[front];

            if (isEmpty())
                throw UnderFlow;
            len--;
            front = (front + 1) % maxSize;
            return outVal;
        }

        bool isEmpty()
        {
            return (len == 0);
        }

        bool isFull()
        {
            return (len == maxSize)
        }

        /*
        void enqueue(int inVal)
        {
            if (numElements == maxSize)
                throw OverFlow;

            data[numElements] = inVal;
        }

        int dequeue()
        {
            if (numElements == 0)
                throw UnderFlow;

            int outVal = data[0];
            numElements--;

            for(int i = 0; i < numElements; i++)
            {
                data[i] = data[i + 1];
            }
            return outVal;
        }
        */
}