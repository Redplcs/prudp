//  
//   (c) Copyright 1998-2001, Quazal
//   ALL RIGHTS RESERVED
//  
//  


#ifndef _ProductKey_H_
#define _ProductKey_H_

#include <ProductInfo/ProductInfoDecl.h>

class ProductInfo;

#define PRODUCT_KEY_MAX_SIZE		64

class ProductKey {

	// Group=
	public:
		ProductKey();
		virtual ~ProductKey();

		static bool Validate(ProductInfo *pProductInfo, unsigned short usProductKeyType);

		void SetNumberOfDaysBeforeWarning(unsigned int uiDays);
		unsigned int GetNumberOfDaysBeforeWarning();
		bool WarnUserForExpirationDate();

	private:
		bool PrivateValidate();
		
		bool ValidateExpirationDateForAllTargetProducts(unsigned char bExpirationType, unsigned long ulExpirationDate);
		bool ValidateCheckSum(unsigned char bComputedCheckSum, unsigned char bRealCheckSum);
		bool ValidateProduct(unsigned short wProductInfo);
		bool ValidateCurrentOS(unsigned char bSupportedOS);

		bool ValidateExpirationDate(unsigned long ulExpirationDate);
		void ReadEncryptedStringKey(unsigned char* pbProductKeyData);
		unsigned char ConvertByteStringToHexa(char* szByteNumber);
		unsigned char GetCharValue(char cNumber);

		void DecryptProductKey(unsigned char* pbData, unsigned long ulDataSize);

		unsigned char ComputeCheckSum(unsigned char* pbData, unsigned long ulDataSize);
		
		char m_szProductKey[PRODUCT_KEY_MAX_SIZE];

		bool m_bInitialize;
		ProductInfo	  *m_pProductInfo;
		unsigned long m_ulCurrentBuildNb;
		bool m_bShiftBuild;

		unsigned int m_uiWarningDaysBeforeExp;
		unsigned short m_wProductKeyUserType;
		unsigned long m_ulExpirationDate;

};

#endif
