Hashing

Option 3:
    // - Putting more than 1 piece of data in a single spot

    // instead of using a 1D area, we are going to use something else

/*        - can use a 2D array (buckets)

                BUCKETS: only work until the bucket is full. Then we need to resort back to option 2 (linear probing).

          - can use an array of link list (chain)

                CHAINS: we will never have to use probing. However with enough collisions, we start heading towards O(n)
                        performance.
