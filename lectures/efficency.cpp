Efficiency - for any given problem, there are multiple solutions. What we want is the most efficient.
             The solution that requires the least amount of resources.
        //resource - # of operations, space, RAM, Run time, or some other.

        // Efficiency is usually measured in big O notation. This is usually reflective of the worst case.
        // depending on the situation the best case or average case are also value measure techniques.
        // when selecting one is it helpful to know how likely that case is to happen.

        // Example:

            // Calculate: 1 + 2 + 3 + 4 + ... + n

                // Option A:

                    sum = 0;
                    for(int i = 1; i <= n; i++)
                    {
                        sum += i;
                    }

                // Option B:

                    sum = 0;
                    for (int i = 1; i <= n; i++)
                    {
                        for(int j = 1; j < i; i++)
                        {
                            sum += 1;
                        }
                    }

                // Option C:

                    sum = n * (n+1)/2;
