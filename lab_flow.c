#include "lab_util.h"
int hex_to_int(char c);
int hex_to_ascii(const char c, const char d);
void printHX(const char* st);
void printBN(char* msg, BIGNUM* a);

BIGNUM* get_rsa_priv_key(BIGNUM* p, BIGNUM* q, BIGNUM* e);
BIGNUM* rsaEnc(BIGNUM* message, BIGNUM* mod, BIGNUM* publicKey);
BIGNUM* rsaDec(BIGNUM* encrypted_message, BIGNUM* priv_key, BIGNUM* publicKey);

int main () {
	printf("=== Starting Lab Flow ===\n\n");	
	/* Task 3.1 */
	printf("=== Task 3.1 ===\n");
	// Init prime numbers as shown in the lab task
	BIGNUM *p = BN_new();
	BN_hex2bn(&p, "F7E75FDC469067FFDC4E847C51F452DF");

	BIGNUM *q = BN_new();
	BN_hex2bn(&q, "E85CED54AF57E53E092113E62F436F4F");

	BIGNUM *e = BN_new();
	BN_hex2bn(&e, "0D88C3");

	BIGNUM* privateKey3_1 = get_rsa_priv_key(p, q, e);
	printBN("Private key: ", privateKey3_1);
	printf("\n");

	/* Task 3.2 */
	printf("=== Task 3.2 ===\n");	
	BIGNUM* enc = BN_new();
	BIGNUM* dec = BN_new();
	// Init private key d
	BIGNUM* privateKey3_2 = BN_new();
	BN_hex2bn(&privateKey3_2, "74D806F9F3A62BAE331FFE3F0A68AFE35B3D2E4794148AACBC26AA381CD7D30D");

	// Init public key n
	BIGNUM* publicKey = BN_new();
	BN_hex2bn(&publicKey, "DCBFFE3E51F62E09CE7032E2677A78946A849DC4CDDE3A4D0CB81629242FB1A5");
	printBN("Public key: ", publicKey);
	printf("\n");

	// Init modulus e
	BIGNUM* mod = BN_new();
	BN_hex2bn(&mod, "010001");
	
	//Init given message
	BIGNUM* message = BN_new();
	BN_hex2bn(&message, "4120746f702073656372657421");

	printBN("Message Hex:", message);
	enc = rsaEnc(message, mod, publicKey);
	printBN("Encrypted message:", enc);
	dec = rsaDec(enc, privateKey3_2, publicKey);
	printf("Decrypted message: ");
	printHX(BN_bn2hex(dec));
	printf("\n");

	/* Task 3.3 */
	printf("=== Task 3.3 ===\n");
	BIGNUM* task3_enc = BN_new();
	BN_hex2bn(&task3_enc, "8C0F971DF2F3672B28811407E2DABBE1DA0FEBBBDFC7DCB67396567EA1E2493F");
	
	dec = rsaDec(task3_enc, privateKey3_2, publicKey);
	printf("Decrypted message: ");
	printHX(BN_bn2hex(dec));
	printf("\n");
}





