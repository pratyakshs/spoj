
#include<stdio.h>
class WeightedQuickUnionUF {
    int *id;    // id[i] = parent of i
    int *sz;    // sz[i] = number of objects in subtree rooted at i
    int count;   // number of components

    /**
     * Initializes an empty union-find data structure with N isolated components 0 through N-1.
     */
    public:
     WeightedQuickUnionUF(int N) {
        count = N;
        id = new int[N];
        sz = new int[N];
        for (int i = 0; i < N; i++) {
            id[i] = i;
            sz[i] = 1;
        }
    }

    /**
     * Return the number of components.
     * @return the number of components (between 1 and N)
     */
    int countr() {
        return count;
    }

    /**
     * Return the component identifier for the component containing object p.
     * @param p the integer representing one object
     * @return the component identifier for the component containing object p
     * @throws java.lang.IndexOutOfBoundsException unless 0 <= p < N
     */
    int find(int p) {
        while (p != id[p])
            p = id[p];
        return p;
    }

    /**
     * Are the two objects p and q in the same component?
     * @param p the integer representing one object
     * @param q the integer representing the other object
     * @return true if the objects p and q are in the same component; false otherwise
     * @throws java.lang.IndexOutOfBoundsException unless both 0 <= p < N and 0 <= q < N
     */
    bool connected(int p, int q) {
        return find(p) == find(q);
    }

  
    /**
     * Merge components containing p and q.
     * @param p the integer representing one object
     * @param q the integer representing the other object
     * @throws java.lang.IndexOutOfBoundsException unless both 0 <= p < N and 0 <= q < N
     */
    void union_(int p, int q) {
        int i = find(p);
        int j = find(q);
        if (i == j) return;

        // make smaller root point to larger one
        if   (sz[i] < sz[j]) { id[i] = j; sz[j] += sz[i]; }
        else                 { id[j] = i; sz[i] += sz[j]; }
        count--;
    }


    /**
     * Reads in a sequence of pairs of integers (between 0 and N-1) from standard input, 
     * where each integer represents some object;
     * if the objects are in different components, merge the two components
     * and print the pair to standard output.
     */
   

};


int main() {
        int N
        scanf("%i", &N);
        WeightedQuickUnionUF uf = new WeightedQuickUnionUF(N);
        while (!StdIn.isEmpty()) {
            int p, q;
            scanf("%i %i", &p, &q);
            if (uf.connected(p, q)) continue;
            uf.union_(p, q);
            printf("%i %i", p, q);
        }
        printf("%i components", uf.countr());
    }