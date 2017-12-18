#include <stdio.h>
#include <string.h>
    /*  1) Alice and Bob agree on an elliptic curve EE over a Field FqFq and a basepoint P∈E/FqP∈E/Fq. (Easily done)
        2) Alice generates a (random) secret kAkA and computes PA=kAPPA=kAP.    Point Arithmetic
        3) Bob generates a (random) secret kBkB and computes PB=kBPPB=kBP.
        4) Alice and Bob exchange PAPA and PBPB.
        5) Alice and Bob compute PAB=kaPB=kbPAPAB=kaPB=kbPA.

The secret kAkA and kBkB is a random value ∈{1,...,n−1}∈{1,...,n−1} where nn is the order of the group generated by PP. */
/* TODO:
    modular_inverse
    montgomery multiplication (if I feel like a fast boi)
    Elgamel's
    Figure out most significant bit of modulus stuff */

typedef struct Point_t{
    int x;
    int y;
}

Point point_operation(Point A, Point B,int s){
    Point temp;
    temp.x = s^2 - A.x - B.x;
    temp.y = s(A.x - ret_x) - A.y;
    return {temp.x, temp.y}; // I know this doesn't compile but you get the point and its easier in verilog
}

// generates shared secret
Point Pa_generator(int k, Point G, int p){ // ok now do this in hardware
    // eqn: y^3 = x^2 + ax + b
    // if odd add 1, double regardless
    Point temp;
    temp.x = P.x;
    temp.y = P.y;
    while(k>0){
        if(k%2 == 0){
            int s = (3(temp.x^2) + a)*(inv_mod(2*temp.y)) % p;
            temp = point_operation(temp, temp, s);
            k >>= 1;
        }
        else{
            int s = (G.y - temp.y)*inv_mod(G.x-temp.x) % p;
            temp = point_operation(G, temp, s);
            k--;
        }
    }
}

void modulus(int k, int n){
    int out = k;
    if(MSBk == 1)
        while(out < 0)
            out += n;
    else
        while(out>n)
            out -= n;
}


// Elgamel's crap
void elgamal_encrypt(Point public_key, int n, int message){
    /* ENCRYPTION: Choose random 1 < k < n. C1 = kG, C2 = kPub.
       Pm is f(m), i.e. <m, f(m)> (y^2 = x^3 + 7; maybe don't use y^2?) Ciphertext is <C1, C2 + Pm>.
       Maybe use C1 = bob_point and C2 = shared point?
       For secp256k1, it would be <bob_point, shared_point + <m, m+7>>*/
}

void elgamal_decrypt(Point public_key, int n, int ciphertext){
    /* DECRYPTION: */
    /* From <C, D> (C1, C2+Pm) calc C' = priv_key*C.
       Pm = D - C' = (k(xP) + Pm) - (x(kP))
       m = inv(f(m)); */
}

int main(){
    // y^2 = x^3 + ax + b
    // domain parameters {a, b, n, G}
    int alice = rand() % n;
    int bob = rand() % n;
    char message[128];
    int message_num = 0;
    scanf("Insert message: %s", message);
    message_num = asciify(message[i]);

    Point point_alice = Pa_generator(alice, G, p);
    Point point_bob = Pa_generator(bob, G, p);
    Point shared_key = Pa_generator(alice, point_bob, p);

    Point cipher = {}
    elgamal_encrypt();
    elgamal_decrypt();
}
