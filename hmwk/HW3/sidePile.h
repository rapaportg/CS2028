#ifndef SIDEPILE_H
#define SIDEPILE_H

class SidePile
{
    private:
        int head = 0;
        int pile[5];

    public:
        class StackOverFlowException
        {
            private:
                int value;

            public:
                StackOverFlowException(int v) {value = v;}
                int getValue() {return value;}
        };

        class StackUnderFlowException
        {
            private:
                int value;

            public:
                StackUnderFlowException(int v) {value = v;}
                int getValue() {return value;}
        };

        void    push(int card);
        int     pop();
        int     size(); // size of pile
        int     look(int index);

};

#endif