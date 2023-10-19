#include <stdio.h>
#include <string.h>
#include <openssl/evp.h>
#include <openssl/err.h>


void tDigest(){
	unsigned char md_value[EVP_MAX_MD_SIZE];
	unsigned int md_len;
	EVP_MD_CTX *mdctx;
	mdctx = EVP_MD_CTX_new();
	char msg1[] = "20211108";
	char msg2[] = "Yu_Zhenyang";
	
	EVP_MD_CTX_init(mdctx);
	EVP_DigestInit_ex(mdctx, EVP_sm3(), NULL);
	EVP_DigestUpdate(mdctx, msg1, strlen(msg1));
	EVP_DigestUpdate(mdctx, msg2, strlen(msg2));
	EVP_DigestFinal_ex(mdctx, md_value, &md_len);
	EVP_MD_CTX_destroy(mdctx);

	printf("Debug:Message1%s and Message2%s digest to:\n",msg1, msg2);
	for(int i = 0; i<md_len; i++){

		printf("0x%02x ", md_value[i]);
	}
	printf("\n");
}

int main(){

	OpenSSL_add_all_algorithms();
	tDigest();
	return 0;
}
