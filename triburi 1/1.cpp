/*
11.5  Perfect hashing
Although hashing is most often used for its excellent expected performance, hashing can be
used to obtain excellent worst-case performance when the set of keys is static: once the keys
are stored in the table, the set of keys never changes. Some applications naturally have static
sets of keys: consider the set of reserved words in a programming language, or the set of file
names on a CD-ROM. We call a hashing technique perfect hashing if the worst-case number
of memory accesses required to perform a search is O(1).
The basic idea to create a perfect hashing scheme is simple. We use a two-level hashing
scheme with universal hashing at each level. Figure 11.6 illustrates the approach.
Figure 11.6: Using perfect hashing to store the set K = {10, 22, 37, 40, 60, 70, 75}. The outer
hash function is h(k) = ((ak + b) mod p) mod m, where a = 3, b = 42, p = 101, and m = 9. For
example, h(75) = 2, so key 75 hashes to slot 2 of table T . A secondary hash table Sj stores all
keys hashing to slot j . The size of hash table Sj is mj , and the associated hash function is hj
(k) = ((aj k + bj) mod p) mod mj. Since h2(75) = 1, key 75 is stored in slot 1 of secondary hash
table S2. There are no collisions in any of the secondary hash tables, and so searching takes
constant time in the worst case.
The first level is essentially the same as for hashing with chaining: the n keys are hashed into
m slots using a hash function h carefully selected from a family of universal hash functions.
Instead of making a list of the keys hashing to slot j, however, we use a small secondary hash
table Sj with an associated hash function hj. By choosing the hash functions hj carefully, we
can guarantee that there are no collisions at the secondary level.
In order to guarantee that there are no collisions at the secondary level, however, we will need
to let the size mj of hash table Sj be the square of the number nj of keys hashing to slot j. While
having such a quadratic dependence of mj on nj may seem likely to cause the overall storage
requirements to be excessive, we shall show that by choosing the first level hash function
well, the expected total amount of space used is still O(n).
We use hash functions chosen from the universal classes of hash functions of Section 11.3.3.
The first-level hash function is chosen from the class .p,m, where as in Section 11.3.3, p is a
prime number greater than any key value. Those keys hashing to slot j are re-hashed into a
secondary hash table Sj of size mj using a hash function hj chosen from the class .[1]
We shall proceed in two steps. First, we shall determine how to ensure that the secondary
tables have no collisions. Second, we shall show that the expected amount of memory used
overall.for the primary hash table and all the secondary hash tables.is O(n).
Theorem 11.9
If we store n keys in a hash table of size m = n2 using a hash function h randomly chosen from
a universal class of hash functions, then the probability of there being any collisions is less
than 1/2.
Proof There are pairs of keys that may collide; each pair collides with probability 1/m if h is
chosen at random from a universal family . of hash functions. Let X be a random variable
that counts the number of collisions. When m = n2, the expected number of collisions is
(Note that this analysis is similar to the analysis of the birthday paradox in Section 5.4.1.)
Applying Markov's inequality (C.29), Pr{X . t} . E[X] /t, with t = 1 completes the proof.
In the situation described in Theorem 11.9, where m = n2, it follows that a hash function h
chosen at random from . is more likely than not to have no collisions. Given the set K of n
keys to be hashed (remember that K is static), it is thus easy to find a collision-free hash
function h with a few random trials.
When n is large, however, a hash table of size m = n2 is excessive. Therefore, we adopt the
two-level hashing approach, and we use the approach of Theorem 11.9 only to hash the
entries within each slot. An outer, or first-level, hash function h is used to hash the keys into
m = n slots. Then, if nj keys hash to slot j, a secondary hash table Sj of size is used to
provide collision-free constant time lookup.
We now turn to the issue of ensuring that the overall memory used is O(n). Since the size mj
of the jth secondary hash table grows quadratically with the number nj of keys stored, there is
a risk that the overall amount of storage could be excessive.
If the first-level table size is m = n, then the amount of memory used is O(n) for the primary
hash table, for the storage of the sizes mj of the secondary hash tables, and for the storage of
the parameters aj and bj defining the secondary hash functions hj drawn from the class of
Section 11.3.3 (except when nj = 1 and we use a = b = 0). The following theorem and a
corollary provide a bound on the expected combined sizes of all the secondary hash tables. A
second corollary bounds the probability that the combined size of all the secondary hash
*/
#include <stdio.h>
#include <string.h>
#include <algorithm>
#define DIM 1011

using namespace std;

struct sat {
	int a;
	int b;
};

int minim(int a, int b) {
	return (a<b ? a:b);
}

sat S[DIM], T[DIM];
int N, i, sol1, sol2, K, h, m, aux, ka, kb, p, u, doar;


int cmpa(sat x, sat y) {
	return x.a<y.a;
}

int cmpb(sat x, sat y) {
	return x.b<y.b;
}

int pot(int b) {
	for (int a=0;a<=b;a++) {
		int ka = K;
		int	kb = K;
		doar = 0;
		for (int i=1;i<=N;i++) {
			if ((S[i].a <= a) && (a + S[i].a + S[i].b <= b)) { // a poi b
				ka --;
				kb --;
				continue;
			}
			if (S[i].a > a && S[i].b >b)  //nici a nici b
				continue;
			if (S[i].a<=a && S[i].b <= b) {  // si a si b
				doar++;
				continue;
			}
			if (S[i].a <= a) {
				ka--;
				continue;
			}
			if (S[i].b <= b) {
				kb--;
				continue;
			}
		}
		if (ka < 0)
			ka = 0;
		if (kb < 0)
			kb = 0;
		if (ka + kb == 0)
			return 1;
		if (ka + kb <= doar)
			return 1;
	}
	return 0;
}

int main() {
	
	FILE *f = fopen("triburi.in", "r");
	FILE *g = fopen("triburi.out", "w");
	fscanf(f,"%d %d",&N, &K);
	
	
	for (i=1;i<=N;i++) {
		fscanf(f,"%d %d",&h, &m);
		S[i].a = h*60 + m;
		fscanf(f,"%d %d",&h, &m);
		S[i].b = h*60 + m;
	}
	fclose(f);
	
	p = 0;
	u = 23*60 + 59;


//  sol1 = 1<<25;
	while (p<=u) {
		m = (p+u) / 2;
		if (pot(m))
			u = m-1;
		else
			p = m+1; //p sol
	}

	sol1 = p;
	
	for (i=1;i<=N;i++) {
		aux = S[i].a;
		S[i].a = S[i].b;
		S[i].b = aux;
	}
	
	p = 0;
	u = 23*60 + 59;

//  sol2 = 1<<25;
	while (p<=u) {
		m = (p+u) / 2;
		if (pot(m))
			u = m-1;
		else
			p = m+1; //p sol
	}
	
	sol2 = p;
	
	p = sol1<sol2 ? sol1 : sol2;

	h = p / 60;
	m = p % 60;
	
	fprintf(g,"%d %d\n",h,m);
	fclose(g);
	return 0;
}
