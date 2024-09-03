#if !defined(FCODER_LEX_GEN_HAND_WRITTEN)
#define FCODER_LEX_GEN_HAND_WRITTEN

internal u64
lexeme_hash(u64 seed, u8 *ptr, u64 size){
    u64 result = 0;
    for (u64 i = 0; i < size; i += 1, ptr += 1){
        result ^= ((*ptr) ^ result*59) + seed;
    }
    return(result);
}

internal Lexeme_Table_Lookup
lexeme_table_lookup(u64 *hash_array, String_Const_u8 *key_array, 
                    Lexeme_Table_Value *value_array, i32 slot_count, u64 seed,
                    u8 *ptr, u64 size){
    Lexeme_Table_Lookup result = {};
    u64 hash = lexeme_hash(seed, ptr, size);
    u64 comparison_hash = hash | 1;
    i32 first_index = (hash % slot_count);
    i32 index = first_index;
    for (;;){
        if (hash_array[index] == comparison_hash){
            if (string_match(SCu8(ptr, size), key_array[index])){
                result.found_match = true;
                result.base_kind = value_array[index].base_kind;
                result.sub_kind = value_array[index].sub_kind;
                break;
            }
        }
        else if (hash_array[index] == 0){
            break;
        }
        index += 1;
        if (index == slot_count){
            index = 0;
        }
        if (index == first_index){
            break;
        }
    }
    return(result);
}

#endif
u64 nasm_main_keys_hash_array[808] = {
0x0000000000000000,0x4aa28da389e5f141,0x0000000000000000,0x0000000000000000,
0xd5190545a6f5d2a5,0x5c101e074f305d35,0x0000000000000000,0x0000000000000000,
0x0000000000000000,0x0c6198b14fb74e81,0x0000000000000000,0xd5190545a6f5d2ab,
0x0000000000000000,0x0c6198b14fb74e85,0x0000000000000000,0x0000000000000000,
0x0000000000000000,0x0000000000000000,0x0000000000000000,0xffebce0cdf55c673,
0x0000000000000000,0x0000000000000000,0x0000000000000000,0xffebd1e99bfd99ef,
0x98759580a0f953d1,0x5c101e074e17b141,0x0000000000000000,0x0000000000000000,
0x60be766c43a416ed,0x0000000000000000,0x0000000000000000,0x0000000000000000,
0x0000000000000000,0x5c101e074f305d51,0xffebd1e3e809f311,0xd47530c57f48598b,
0x0000000000000000,0x0000000000000000,0x0c6198b14fb74e9f,0x0000000000000000,
0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000,
0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000,
0x0000000000000000,0x4aa28da389e5b8a1,0x0000000000000000,0x0000000000000000,
0x0000000000000000,0x4aa28da389e5bbcd,0xd5190545a6f5d2d5,0xd5190545a6f5d2d7,
0x0c6198b14fb74eb1,0x0000000000000000,0x0000000000000000,0x0000000000000000,
0x0000000000000000,0x4aa28da389e5bbd5,0x0000000000000000,0x0000000000000000,
0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000,
0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000,
0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000,
0x0000000000000000,0x4aa28da389e5f18d,0x0000000000000000,0x0000000000000000,
0x0000000000000000,0xffebd1ef4fe53241,0x0000000000000000,0x0000000000000000,
0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000,
0xd5190545a6f5d2f9,0x4aa28da389e5c891,0x4aa28da389e5c891,0x4aa28da389e5c893,
0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000,
0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000,
0x4aa28da389e5c89d,0x0000000000000000,0x0000000000000000,0x4aa28da389e5c89f,
0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000,
0x17e9878b92c659c5,0x0c6198b14fb74ee5,0x0000000000000000,0x0000000000000000,
0x0000000000000000,0x0c6198b14fb74ee9,0x0000000000000000,0x0000000000000000,
0x0000000000000000,0x0000000000000000,0x4aa28da389e5bf37,0x0000000000000000,
0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000,
0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000,
0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000,
0x23495534b679ca45,0x0000000000000000,0x4aa28da389e5b5cf,0x0000000000000000,
0xd5190545a738af81,0xd5190545a738af81,0xd5190545a738af83,0xd5190545a738af83,
0x0000000000000000,0x0000000000000000,0xd5190545a738af87,0x0000000000000000,
0xffebd1e502d5f469,0xd5190545a738af89,0x0000000000000000,0x0000000000000000,
0xd5190545a738af8d,0xd5190545a738af8d,0xd5190545a738af8f,0xd5190545a738af8f,
0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000,
0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000,
0x0000000000000000,0x0000000000000000,0x0000000000000000,0xd5190545a6f5d343,
0x0000000000000000,0x4aa28da389e5f50d,0x0000000000000000,0x0000000000000000,
0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000,
0x4f86354539792dc5,0xd5190545a6f5d34d,0x0000000000000000,0x0000000000000000,
0x0000000000000000,0x4aa28da389e5b5f9,0x0000000000000000,0x0000000000000000,
0x0000000000000000,0x4aa28da389e5f1f5,0x4aa28da389e5e555,0x4aa28da389e5e557,
0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000,
0x0000000000000000,0xd5190545a6f5d35d,0x0000000000000000,0x0000000000000000,
0x0000000000000000,0xd5190545a7577291,0x0000000000000000,0x0000000000000000,
0xa210efd33367bd6d,0x0c6198b14fb7b115,0x0000000000000000,0x0000000000000000,
0x0000000000000000,0x4aa28da389e521b9,0x0000000000000000,0x0000000000000000,
0x0000000000000000,0xffebd1e36495b1ad,0x0c6198b14fb7b11d,0x0000000000000000,
0x0000000000000000,0x5c101e074f305e01,0x0000000000000000,0x0000000000000000,
0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000,
0x4aa28da389e5e579,0x0000000000000000,0x0000000000000000,0x0000000000000000,
0x10b38a13e8f102fd,0x0000000000000000,0x0000000000000000,0x0000000000000000,
0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000,
0x0000000000000000,0x0c6198b14fb7b135,0x4aa28da389de114d,0x0000000000000000,
0x0000000000000000,0x0c6198b14fb7b139,0x4aa28da389e5b959,0xffebd1e3e809f3d9,
0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000,
0x0c6198b14fb7b141,0x0000000000000000,0x0000000000000000,0x0000000000000000,
0x0000000000000000,0x0c6198b14fb7b145,0x4aa28da389e5e595,0x0000000000000000,
0x4aa28da389de1e01,0x4aa28da389de1e01,0xffebd1e3e809f3e9,0x4aa28da389de1e03,
0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000,
0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000,
0x4aa28da389e5e5a5,0x0000000000000000,0x0000000000000000,0x0000000000000000,
0x0000000000000000,0x0000000000000000,0x0000000000000000,0x4aa28da389e5e5ab,
0x0000000000000000,0x0000000000000000,0x4aa28da389e5f577,0x0000000000000000,
0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000,
0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000,
0x0000000000000000,0x0000000000000000,0x0000000000000000,0x9875951b6decfd3b,
0x0000000000000000,0x4aa28da389e5bfdd,0x987597b722c2f857,0xd5190545a71d5137,
0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000,
0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000,
0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000,
0x0000000000000000,0x4aa28da389de1e35,0x0000000000000000,0x0000000000000000,
0x0000000000000000,0xffebd1e3e809f421,0x0000000000000000,0x4aa28da389de1e3b,
0x4aa28da389de1e3d,0x4aa28da389de1e3d,0x4aa28da389de1e3f,0x4aa28da389de1e3f,
0x0000000000000000,0xd5190545a6f5d0b1,0x0000000000000000,0xd5190545a6f5d0b3,
0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000,
0xd5190545a71197c1,0x0c6198b14fb74fb9,0xd5190545a71197c1,0xd5190545a71197c3,
0xd5190545a71197c3,0x0000000000000000,0xd5190545a71197c7,0x0000000000000000,
0x0000000000000000,0xd5190545a71197c9,0x0000000000000000,0x0000000000000000,
0xd5190545a71197cd,0xd5190545a71197cd,0xd5190545a71197cf,0xd5190545a71197cf,
0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000,
0x0000000000000000,0xffebd1e3e809f445,0x0000000000000000,0x0000000000000000,
0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000,
0x0000000000000000,0x0c6198b14fb7b1ad,0x0000000000000000,0x0000000000000000,
0x0000000000000000,0x5c101e074f305e91,0x0000000000000000,0x0000000000000000,
0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000,
0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000,
0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000,
0x0000000000000000,0x0c6198b14fb7b1c1,0x0000000000000000,0x0000000000000000,
0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000,
0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000,
0x0000000000000000,0x4aa28da389e461e5,0x0000000000000000,0x0000000000000000,
0x0000000000000000,0x0c6198b14fb7b1d1,0x0000000000000000,0x0000000000000000,
0x5c101e077b2012dd,0x184c55b87e29ddc5,0x0c6198b14fb7b1d5,0x0000000000000000,
0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000,
0x17e99400ea46a845,0x17e9940ebb6fca45,0x4aa28da389e5c04d,0x0000000000000000,
0xffebd1e26b9bd141,0x0000000000000000,0x0000000000000000,0x0000000000000000,
0x0000000000000000,0x4aa28da389e5ba05,0x0000000000000000,0x0000000000000000,
0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000,
0x3658b24fe5f102fd,0x0000000000000000,0x0000000000000000,0x0000000000000000,
0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000,
0x0000000000000000,0x0000000000000000,0x0c6198b14fb74cf7,0x0000000000000000,
0xffebd1e9f0852a69,0x5c101e074f305ed9,0x5c101e074f305ed9,0x5c101e074f305edb,
0x0000000000000000,0x0c6198b14fb74cfd,0x0000000000000000,0x0000000000000000,
0x0000000000000000,0x0000000000000000,0xd477a478d4313723,0x5c101e074f305ee3,
0x0000000000000000,0x5c101e074f305ee5,0x5c101e074f305ee7,0x0000000000000000,
0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000,
0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000,
0x4aa28da389e5ad91,0x4aa28da389e5ad91,0x4aa28da389e5ad93,0x0000000000000000,
0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000,
0x172bbbcc8ab70141,0xd5190545a6f5d141,0x0000000000000000,0x4aa28da389e5ad9b,
0x4aa28da389e5ad9d,0x4aa28da389e5ad9d,0x4aa28da389e5ad9f,0x4aa28da389e5ad9f,
0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000,
0x2b130a1a6aa5ddc5,0x0000000000000000,0x0000000000000000,0xd5190545a75c2fa7,
0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000,
0x17e9940bdbd80745,0x17e987f72d0c1325,0x0000000000000000,0x0000000000000000,
0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000,
0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000,
0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000,
0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000,
0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000,
0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000,
0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000,
0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000,
0x0000000000000000,0x0000000000000000,0xffebd1e674e21dcb,0x0000000000000000,
0x0000000000000000,0xffebd1e3e809f4f5,0x4aa28da389e5f01f,0x0000000000000000,
0x0000000000000000,0xd5190545a75c0081,0x0000000000000000,0x0000000000000000,
0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000,
0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000,
0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000,
0x4aa28da389e51991,0x4aa28da389e5f031,0x0000000000000000,0x0000000000000000,
0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000,
0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000,
0x0000000000000000,0x0c6198b14fb74d75,0x0c6198b14fb74d77,0x0000000000000000,
0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000,
0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000,
0x0000000000000000,0x4aa28da389e5f699,0x0000000000000000,0x0000000000000000,
0x234955407340b9c5,0x8c6345b6e563f9c5,0x0000000000000000,0x0000000000000000,
0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000,
0x0000000000000000,0x0000000000000000,0x5c101e074251c727,0x0000000000000000,
0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000,
0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000,
0x0000000000000000,0x9875951b09ba1cf1,0x0000000000000000,0x0000000000000000,
0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000,
0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000,
0x0000000000000000,0x987594f8c11cf865,0x0000000000000000,0x0000000000000000,
0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000,
0x17e9940c4b466a45,0x0000000000000000,0x0000000000000000,0x0000000000000000,
0xd5190545a6f5d1d9,0x5c101e074d2bc8b1,0x0000000000000000,0x0000000000000000,
0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000,
0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000,
0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000,
0x0000000000000000,0xffebd1e9999e4441,0x0000000000000000,0x0000000000000000,
0x0000000000000000,0x5c101e074da3a5d5,0xd5190545a6f5d1ed,0x0000000000000000,
0x0000000000000000,0x5c101e074f305fa9,0x0000000000000000,0x0000000000000000,
0x44922d934328fced,0x0000000000000000,0x0000000000000000,0xd5190545a6f5d1f7,
0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000,
0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000,
0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000,
0x0000000000000000,0x4aa28da389e5c79d,0x0000000000000000,0x0000000000000000,
0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000,
0x3658b29f4e49bcfd,0x0000000000000000,0x0000000000000000,0x0000000000000000,
0x5c101e07561cedd9,0x5c101e07561cedd9,0x0000000000000000,0x5c101e07561ceddb,
0xd5190545a6f5d215,0x5c101e074f305ca5,0x0000000000000000,0x0000000000000000,
0x0000000000000000,0x0000000000000000,0x5c101e07561cede3,0x0000000000000000,
0x0000000000000000,0x5c101e07561cede5,0x5c101e07561cede7,0x0000000000000000,
0x0000000000000000,0xd5190545a6f5d221,0x0000000000000000,0x0000000000000000,
0x0000000000000000,0x4aa28da389e5f0c5,0x0000000000000000,0x0000000000000000,
0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000,
0x0000000000000000,0x5c101e074f305fe5,0x0000000000000000,0xd5190545a6f5d22f,
0x0000000000000000,0x9875951a082e22c9,0x0000000000000000,0x0000000000000000,
0x0c6198b14fb74e0d,0x0000000000000000,0x0000000000000000,0x0000000000000000,
0x0000000000000000,0x0000000000000000,0x0000000000000000,0x5c101e07f6455e8b,
0x4d3ce0d87bdf34fd,0x0000000000000000,0x0000000000000000,0x0000000000000000,
0x5c101e074ddc2a69,0x0000000000000000,0x0000000000000000,0x0000000000000000,
0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000,
0x0000000000000000,0x0000000000000000,0x0000000000000000,0xffebce0d7e01ec0b,
0x0000000000000000,0x0000000000000000,0x0000000000000000,0xd5190545a7574227,
0x0c6198b14fb74b01,0x0c6198b14fb74e29,0x0000000000000000,0x0000000000000000,
0x0000000000000000,0x4aa28da389e5a20d,0x0000000000000000,0x0000000000000000,
0x4aa28da389e50769,0x0000000000000000,0x0000000000000000,0x0000000000000000,
0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000,
0x0000000000000000,0x0000000000000000,0x17e9efb755f6c82b,0x0000000000000000,
0xd5190545a6e623a5,0x0000000000000000,0x0000000000000000,0x0000000000000000,
0x0000000000000000,0x0000000000000000,0x4aa28da389de1ffb,0x0000000000000000,
0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000,
0x0000000000000000,0x5c101e074f305061,0x0000000000000000,0x0000000000000000,
0xba678c7165f92dc5,0x0000000000000000,0x0000000000000000,0x0000000000000000,
0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000,
0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000,
0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000,
0x0000000000000000,0x5c101e074f305075,0x0000000000000000,0x0000000000000000,
0x0000000000000000,0x0000000000000000,0x4aa28da389e5e7b3,0x0000000000000000,
0x0000000000000000,0x4aa28da389e5e7b5,0x4aa28da389e5e7b7,0x0000000000000000,
0x4aa28da389e5e7b9,0x4aa28da389e5e7b9,0x0000000000000000,0x4aa28da389e5e7bb,
0x0000000000000000,0xd5190545a6f5d295,0x0000000000000000,0x0000000000000000,
0x0000000000000000,0x0c6198b14fb74e71,0x5c101e074f305d29,0x0000000000000000,
0x0c6198b14fb74e75,0x0000000000000000,0x0000000000000000,0x0000000000000000,
};
u8 nasm_main_keys_key_array_1[] = {0x72,0x61,0x78,};
u8 nasm_main_keys_key_array_4[] = {0x72,0x31,0x31,0x77,};
u8 nasm_main_keys_key_array_5[] = {0x79,0x6d,0x6d,0x37,0x68,};
u8 nasm_main_keys_key_array_9[] = {0x64,0x68,};
u8 nasm_main_keys_key_array_11[] = {0x72,0x31,0x31,0x62,};
u8 nasm_main_keys_key_array_13[] = {0x64,0x6c,};
u8 nasm_main_keys_key_array_19[] = {0x61,0x6c,0x69,0x67,0x6e,0x62,};
u8 nasm_main_keys_key_array_23[] = {0x65,0x78,0x74,0x65,0x72,0x6e,};
u8 nasm_main_keys_key_array_24[] = {0x77,0x61,0x72,0x6e,0x69,0x6e,0x67,};
u8 nasm_main_keys_key_array_25[] = {0x73,0x74,0x72,0x75,0x63,};
u8 nasm_main_keys_key_array_28[] = {0x5f,0x5f,0x6e,0x61,0x73,0x6d,0x5f,0x76,0x65,0x72,0x73,0x69,0x6f,0x6e,0x5f,0x69,0x64,0x5f,0x5f,};
u8 nasm_main_keys_key_array_33[] = {0x79,0x6d,0x6d,0x39,0x68,};
u8 nasm_main_keys_key_array_34[] = {0x79,0x6d,0x6d,0x31,0x31,0x68,};
u8 nasm_main_keys_key_array_35[] = {0x73,0x65,0x63,0x74,0x61,0x6c,0x69,0x67,0x6e,};
u8 nasm_main_keys_key_array_38[] = {0x64,0x69,};
u8 nasm_main_keys_key_array_49[] = {0x65,0x61,0x78,};
u8 nasm_main_keys_key_array_53[] = {0x65,0x62,0x70,};
u8 nasm_main_keys_key_array_54[] = {0x72,0x31,0x34,0x64,};
u8 nasm_main_keys_key_array_55[] = {0x72,0x31,0x34,0x62,};
u8 nasm_main_keys_key_array_56[] = {0x65,0x73,};
u8 nasm_main_keys_key_array_61[] = {0x65,0x62,0x78,};
u8 nasm_main_keys_key_array_77[] = {0x72,0x62,0x70,};
u8 nasm_main_keys_key_array_81[] = {0x69,0x6d,0x70,0x6f,0x72,0x74,};
u8 nasm_main_keys_key_array_88[] = {0x72,0x31,0x34,0x77,};
u8 nasm_main_keys_key_array_89[] = {0x74,0x72,0x37,};
u8 nasm_main_keys_key_array_90[] = {0x74,0x72,0x34,};
u8 nasm_main_keys_key_array_91[] = {0x74,0x72,0x35,};
u8 nasm_main_keys_key_array_100[] = {0x74,0x72,0x33,};
u8 nasm_main_keys_key_array_103[] = {0x74,0x72,0x36,};
u8 nasm_main_keys_key_array_108[] = {0x5f,0x5f,0x74,0x69,0x6d,0x65,0x5f,0x5f,};
u8 nasm_main_keys_key_array_109[] = {0x62,0x68,};
u8 nasm_main_keys_key_array_113[] = {0x62,0x6c,};
u8 nasm_main_keys_key_array_118[] = {0x65,0x73,0x69,};
u8 nasm_main_keys_key_array_132[] = {0x5f,0x5f,0x75,0x74,0x63,0x5f,0x64,0x61,0x74,0x65,0x5f,0x5f,};
u8 nasm_main_keys_key_array_134[] = {0x65,0x64,0x69,};
u8 nasm_main_keys_key_array_136[] = {0x78,0x6d,0x6d,0x33,};
u8 nasm_main_keys_key_array_137[] = {0x78,0x6d,0x6d,0x30,};
u8 nasm_main_keys_key_array_138[] = {0x78,0x6d,0x6d,0x35,};
u8 nasm_main_keys_key_array_139[] = {0x78,0x6d,0x6d,0x32,};
u8 nasm_main_keys_key_array_142[] = {0x78,0x6d,0x6d,0x31,};
u8 nasm_main_keys_key_array_144[] = {0x72,0x66,0x6c,0x61,0x67,0x73,};
u8 nasm_main_keys_key_array_145[] = {0x78,0x6d,0x6d,0x38,};
u8 nasm_main_keys_key_array_148[] = {0x78,0x6d,0x6d,0x37,};
u8 nasm_main_keys_key_array_149[] = {0x78,0x6d,0x6d,0x34,};
u8 nasm_main_keys_key_array_150[] = {0x78,0x6d,0x6d,0x39,};
u8 nasm_main_keys_key_array_151[] = {0x78,0x6d,0x6d,0x36,};
u8 nasm_main_keys_key_array_163[] = {0x72,0x31,0x35,0x62,};
u8 nasm_main_keys_key_array_165[] = {0x72,0x73,0x70,};
u8 nasm_main_keys_key_array_172[] = {0x5f,0x5f,0x64,0x61,0x74,0x65,0x5f,0x6e,0x75,0x6d,0x5f,0x5f,};
u8 nasm_main_keys_key_array_173[] = {0x72,0x31,0x35,0x77,};
u8 nasm_main_keys_key_array_177[] = {0x65,0x64,0x78,};
u8 nasm_main_keys_key_array_181[] = {0x72,0x62,0x78,};
u8 nasm_main_keys_key_array_182[] = {0x72,0x38,0x64,};
u8 nasm_main_keys_key_array_183[] = {0x72,0x38,0x62,};
u8 nasm_main_keys_key_array_189[] = {0x72,0x31,0x35,0x64,};
u8 nasm_main_keys_key_array_193[] = {0x6c,0x69,0x73,0x74,};
u8 nasm_main_keys_key_array_196[] = {0x5f,0x5f,0x6f,0x75,0x74,0x70,0x75,0x74,0x5f,0x66,0x6f,0x72,0x6d,0x61,0x74,0x5f,0x5f,};
u8 nasm_main_keys_key_array_197[] = {0x62,0x78,};
u8 nasm_main_keys_key_array_201[] = {0x6d,0x61,0x70,};
u8 nasm_main_keys_key_array_205[] = {0x67,0x6c,0x6f,0x62,0x61,0x6c,};
u8 nasm_main_keys_key_array_206[] = {0x62,0x70,};
u8 nasm_main_keys_key_array_209[] = {0x79,0x6d,0x6d,0x38,0x68,};
u8 nasm_main_keys_key_array_216[] = {0x72,0x38,0x77,};
u8 nasm_main_keys_key_array_220[] = {0x5f,0x5f,0x6e,0x61,0x73,0x6d,0x5f,0x73,0x75,0x62,0x6d,0x69,0x6e,0x6f,0x72,0x5f,0x5f,};
u8 nasm_main_keys_key_array_229[] = {0x63,0x68,};
u8 nasm_main_keys_key_array_230[] = {0x62,0x70,0x6c,};
u8 nasm_main_keys_key_array_233[] = {0x63,0x6c,};
u8 nasm_main_keys_key_array_234[] = {0x65,0x69,0x70,};
u8 nasm_main_keys_key_array_235[] = {0x79,0x6d,0x6d,0x31,0x34,0x68,};
u8 nasm_main_keys_key_array_240[] = {0x63,0x73,};
u8 nasm_main_keys_key_array_245[] = {0x63,0x78,};
u8 nasm_main_keys_key_array_246[] = {0x72,0x39,0x64,};
u8 nasm_main_keys_key_array_248[] = {0x63,0x72,0x37,};
u8 nasm_main_keys_key_array_249[] = {0x63,0x72,0x34,};
u8 nasm_main_keys_key_array_250[] = {0x79,0x6d,0x6d,0x31,0x35,0x68,};
u8 nasm_main_keys_key_array_251[] = {0x63,0x72,0x35,};
u8 nasm_main_keys_key_array_260[] = {0x72,0x39,0x77,};
u8 nasm_main_keys_key_array_267[] = {0x72,0x39,0x62,};
u8 nasm_main_keys_key_array_270[] = {0x72,0x73,0x69,};
u8 nasm_main_keys_key_array_283[] = {0x73,0x65,0x63,0x74,0x69,0x6f,0x6e,};
u8 nasm_main_keys_key_array_285[] = {0x65,0x73,0x70,};
u8 nasm_main_keys_key_array_286[] = {0x6c,0x69,0x62,0x72,0x61,0x72,0x79,};
u8 nasm_main_keys_key_array_287[] = {0x67,0x64,0x74,0x72,};
u8 nasm_main_keys_key_array_301[] = {0x63,0x72,0x38,};
u8 nasm_main_keys_key_array_305[] = {0x79,0x6d,0x6d,0x31,0x30,0x68,};
u8 nasm_main_keys_key_array_307[] = {0x63,0x72,0x32,};
u8 nasm_main_keys_key_array_308[] = {0x63,0x72,0x33,};
u8 nasm_main_keys_key_array_309[] = {0x63,0x72,0x30,};
u8 nasm_main_keys_key_array_310[] = {0x63,0x72,0x31,};
u8 nasm_main_keys_key_array_311[] = {0x63,0x72,0x36,};
u8 nasm_main_keys_key_array_313[] = {0x72,0x31,0x32,0x64,};
u8 nasm_main_keys_key_array_315[] = {0x72,0x31,0x32,0x62,};
u8 nasm_main_keys_key_array_320[] = {0x79,0x6d,0x6d,0x33,};
u8 nasm_main_keys_key_array_321[] = {0x69,0x70,};
u8 nasm_main_keys_key_array_322[] = {0x79,0x6d,0x6d,0x30,};
u8 nasm_main_keys_key_array_323[] = {0x79,0x6d,0x6d,0x35,};
u8 nasm_main_keys_key_array_324[] = {0x79,0x6d,0x6d,0x32,};
u8 nasm_main_keys_key_array_326[] = {0x79,0x6d,0x6d,0x31,};
u8 nasm_main_keys_key_array_329[] = {0x79,0x6d,0x6d,0x38,};
u8 nasm_main_keys_key_array_332[] = {0x79,0x6d,0x6d,0x37,};
u8 nasm_main_keys_key_array_333[] = {0x79,0x6d,0x6d,0x34,};
u8 nasm_main_keys_key_array_334[] = {0x79,0x6d,0x6d,0x39,};
u8 nasm_main_keys_key_array_335[] = {0x79,0x6d,0x6d,0x36,};
u8 nasm_main_keys_key_array_341[] = {0x79,0x6d,0x6d,0x31,0x32,0x68,};
u8 nasm_main_keys_key_array_349[] = {0x61,0x6c,};
u8 nasm_main_keys_key_array_353[] = {0x79,0x6d,0x6d,0x31,0x68,};
u8 nasm_main_keys_key_array_369[] = {0x61,0x78,};
u8 nasm_main_keys_key_array_381[] = {0x69,0x70,0x6c,};
u8 nasm_main_keys_key_array_385[] = {0x61,0x68,};
u8 nasm_main_keys_key_array_388[] = {0x64,0x65,0x62,0x75,0x67,};
u8 nasm_main_keys_key_array_389[] = {0x5f,0x5f,0x75,0x74,0x63,0x5f,0x74,0x69,0x6d,0x65,0x5f,0x6e,0x75,0x6d,0x5f,0x5f,};
u8 nasm_main_keys_key_array_390[] = {0x61,0x74,};
u8 nasm_main_keys_key_array_396[] = {0x5f,0x5f,0x62,0x69,0x74,0x73,0x5f,0x5f,};
u8 nasm_main_keys_key_array_397[] = {0x5f,0x5f,0x64,0x61,0x74,0x65,0x5f,0x5f,};
u8 nasm_main_keys_key_array_398[] = {0x73,0x70,0x6c,};
u8 nasm_main_keys_key_array_400[] = {0x69,0x73,0x74,0x72,0x75,0x63,};
u8 nasm_main_keys_key_array_405[] = {0x65,0x63,0x78,};
u8 nasm_main_keys_key_array_412[] = {0x5f,0x5f,0x6e,0x61,0x73,0x6d,0x5f,0x6d,0x69,0x6e,0x6f,0x72,0x5f,0x5f,};
u8 nasm_main_keys_key_array_422[] = {0x73,0x69,};
u8 nasm_main_keys_key_array_424[] = {0x65,0x66,0x6c,0x61,0x67,0x73,};
u8 nasm_main_keys_key_array_425[] = {0x79,0x6d,0x6d,0x31,0x33,};
u8 nasm_main_keys_key_array_426[] = {0x79,0x6d,0x6d,0x31,0x30,};
u8 nasm_main_keys_key_array_427[] = {0x79,0x6d,0x6d,0x31,0x32,};
u8 nasm_main_keys_key_array_429[] = {0x73,0x70,};
u8 nasm_main_keys_key_array_434[] = {0x75,0x70,0x70,0x65,0x72,0x63,0x61,0x73,0x65,};
u8 nasm_main_keys_key_array_435[] = {0x79,0x6d,0x6d,0x31,0x35,};
u8 nasm_main_keys_key_array_437[] = {0x79,0x6d,0x6d,0x31,0x34,};
u8 nasm_main_keys_key_array_438[] = {0x79,0x6d,0x6d,0x31,0x31,};
u8 nasm_main_keys_key_array_448[] = {0x64,0x72,0x37,};
u8 nasm_main_keys_key_array_449[] = {0x64,0x72,0x34,};
u8 nasm_main_keys_key_array_450[] = {0x64,0x72,0x35,};
u8 nasm_main_keys_key_array_456[] = {0x65,0x6e,0x64,0x73,0x74,0x72,0x75,0x63,};
u8 nasm_main_keys_key_array_457[] = {0x72,0x31,0x32,0x77,};
u8 nasm_main_keys_key_array_459[] = {0x64,0x72,0x32,};
u8 nasm_main_keys_key_array_460[] = {0x64,0x72,0x33,};
u8 nasm_main_keys_key_array_461[] = {0x64,0x72,0x30,};
u8 nasm_main_keys_key_array_462[] = {0x64,0x72,0x31,};
u8 nasm_main_keys_key_array_463[] = {0x64,0x72,0x36,};
u8 nasm_main_keys_key_array_468[] = {0x5f,0x5f,0x74,0x69,0x6d,0x65,0x5f,0x6e,0x75,0x6d,0x5f,0x5f,};
u8 nasm_main_keys_key_array_471[] = {0x69,0x64,0x74,0x72,};
u8 nasm_main_keys_key_array_476[] = {0x5f,0x5f,0x6c,0x69,0x6e,0x65,0x5f,0x5f,};
u8 nasm_main_keys_key_array_477[] = {0x5f,0x5f,0x70,0x61,0x73,0x73,0x5f,0x5f,};
u8 nasm_main_keys_key_array_514[] = {0x6d,0x6f,0x64,0x75,0x6c,0x65,};
u8 nasm_main_keys_key_array_517[] = {0x79,0x6d,0x6d,0x31,0x33,0x68,};
u8 nasm_main_keys_key_array_518[] = {0x72,0x64,0x69,};
u8 nasm_main_keys_key_array_521[] = {0x69,0x65,0x6e,0x64,};
u8 nasm_main_keys_key_array_536[] = {0x6f,0x72,0x67,};
u8 nasm_main_keys_key_array_537[] = {0x72,0x64,0x78,};
u8 nasm_main_keys_key_array_549[] = {0x72,0x38,};
u8 nasm_main_keys_key_array_550[] = {0x72,0x39,};
u8 nasm_main_keys_key_array_561[] = {0x72,0x69,0x70,};
u8 nasm_main_keys_key_array_564[] = {0x5f,0x5f,0x75,0x74,0x63,0x5f,0x74,0x69,0x6d,0x65,0x5f,0x5f,};
u8 nasm_main_keys_key_array_565[] = {0x5f,0x5f,0x70,0x6f,0x73,0x69,0x78,0x5f,0x74,0x69,0x6d,0x65,0x5f,0x5f,};
u8 nasm_main_keys_key_array_574[] = {0x6f,0x73,0x61,0x62,0x69,};
u8 nasm_main_keys_key_array_585[] = {0x73,0x65,0x67,0x6d,0x65,0x6e,0x74,};
u8 nasm_main_keys_key_array_597[] = {0x64,0x65,0x66,0x61,0x75,0x6c,0x74,};
u8 nasm_main_keys_key_array_604[] = {0x5f,0x5f,0x66,0x69,0x6c,0x65,0x5f,0x5f,};
u8 nasm_main_keys_key_array_608[] = {0x72,0x31,0x30,0x77,};
u8 nasm_main_keys_key_array_609[] = {0x67,0x72,0x6f,0x75,0x70,};
u8 nasm_main_keys_key_array_625[] = {0x65,0x78,0x70,0x6f,0x72,0x74,};
u8 nasm_main_keys_key_array_629[] = {0x66,0x6c,0x6f,0x61,0x74,};
u8 nasm_main_keys_key_array_630[] = {0x72,0x31,0x30,0x64,};
u8 nasm_main_keys_key_array_633[] = {0x79,0x6d,0x6d,0x35,0x68,};
u8 nasm_main_keys_key_array_636[] = {0x5f,0x5f,0x5f,0x6e,0x61,0x73,0x6d,0x5f,0x70,0x61,0x74,0x63,0x68,0x6c,0x65,0x76,0x65,0x6c,0x5f,0x5f,};
u8 nasm_main_keys_key_array_639[] = {0x72,0x31,0x30,0x62,};
u8 nasm_main_keys_key_array_653[] = {0x73,0x69,0x6c,};
u8 nasm_main_keys_key_array_660[] = {0x5f,0x5f,0x6e,0x61,0x73,0x6d,0x5f,0x6d,0x61,0x6a,0x6f,0x72,0x5f,0x5f,};
u8 nasm_main_keys_key_array_664[] = {0x78,0x6d,0x6d,0x31,0x33,};
u8 nasm_main_keys_key_array_665[] = {0x78,0x6d,0x6d,0x31,0x30,};
u8 nasm_main_keys_key_array_667[] = {0x78,0x6d,0x6d,0x31,0x32,};
u8 nasm_main_keys_key_array_668[] = {0x72,0x31,0x33,0x77,};
u8 nasm_main_keys_key_array_669[] = {0x79,0x6d,0x6d,0x36,0x68,};
u8 nasm_main_keys_key_array_674[] = {0x78,0x6d,0x6d,0x31,0x35,};
u8 nasm_main_keys_key_array_677[] = {0x78,0x6d,0x6d,0x31,0x34,};
u8 nasm_main_keys_key_array_678[] = {0x78,0x6d,0x6d,0x31,0x31,};
u8 nasm_main_keys_key_array_681[] = {0x72,0x31,0x33,0x64,};
u8 nasm_main_keys_key_array_685[] = {0x72,0x63,0x78,};
u8 nasm_main_keys_key_array_693[] = {0x79,0x6d,0x6d,0x32,0x68,};
u8 nasm_main_keys_key_array_695[] = {0x72,0x31,0x33,0x62,};
u8 nasm_main_keys_key_array_697[] = {0x73,0x61,0x66,0x65,0x73,0x65,0x68,};
u8 nasm_main_keys_key_array_700[] = {0x66,0x73,};
u8 nasm_main_keys_key_array_707[] = {0x61,0x6c,0x69,0x67,0x6e,};
u8 nasm_main_keys_key_array_708[] = {0x5f,0x5f,0x6e,0x61,0x73,0x6d,0x5f,0x76,0x65,0x72,0x5f,0x5f,};
u8 nasm_main_keys_key_array_712[] = {0x66,0x6c,0x61,0x67,0x73,};
u8 nasm_main_keys_key_array_723[] = {0x63,0x6f,0x6d,0x6d,0x6f,0x6e,};
u8 nasm_main_keys_key_array_727[] = {0x6c,0x64,0x74,0x72,};
u8 nasm_main_keys_key_array_728[] = {0x73,0x73,};
u8 nasm_main_keys_key_array_729[] = {0x67,0x73,};
u8 nasm_main_keys_key_array_733[] = {0x64,0x69,0x6c,};
u8 nasm_main_keys_key_array_736[] = {0x78,0x73,0x73,};
u8 nasm_main_keys_key_array_746[] = {0x61,0x62,0x73,0x6f,0x6c,0x75,0x74,0x65,};
u8 nasm_main_keys_key_array_748[] = {0x62,0x69,0x74,0x73,};
u8 nasm_main_keys_key_array_754[] = {0x63,0x70,0x75,};
u8 nasm_main_keys_key_array_761[] = {0x79,0x6d,0x6d,0x30,0x68,};
u8 nasm_main_keys_key_array_764[] = {0x5f,0x5f,0x75,0x74,0x63,0x5f,0x64,0x61,0x74,0x65,0x5f,0x6e,0x75,0x6d,0x5f,0x5f,};
u8 nasm_main_keys_key_array_781[] = {0x79,0x6d,0x6d,0x33,0x68,};
u8 nasm_main_keys_key_array_786[] = {0x72,0x31,0x35,};
u8 nasm_main_keys_key_array_789[] = {0x72,0x31,0x34,};
u8 nasm_main_keys_key_array_790[] = {0x72,0x31,0x31,};
u8 nasm_main_keys_key_array_792[] = {0x72,0x31,0x33,};
u8 nasm_main_keys_key_array_793[] = {0x72,0x31,0x30,};
u8 nasm_main_keys_key_array_795[] = {0x72,0x31,0x32,};
u8 nasm_main_keys_key_array_797[] = {0x72,0x31,0x31,0x64,};
u8 nasm_main_keys_key_array_801[] = {0x64,0x78,};
u8 nasm_main_keys_key_array_802[] = {0x79,0x6d,0x6d,0x34,0x68,};
u8 nasm_main_keys_key_array_804[] = {0x64,0x73,};
String_Const_u8 nasm_main_keys_key_array[808] = {
{0, 0},
{nasm_main_keys_key_array_1, 3},
{0, 0},
{0, 0},
{nasm_main_keys_key_array_4, 4},
{nasm_main_keys_key_array_5, 5},
{0, 0},
{0, 0},
{0, 0},
{nasm_main_keys_key_array_9, 2},
{0, 0},
{nasm_main_keys_key_array_11, 4},
{0, 0},
{nasm_main_keys_key_array_13, 2},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{nasm_main_keys_key_array_19, 6},
{0, 0},
{0, 0},
{0, 0},
{nasm_main_keys_key_array_23, 6},
{nasm_main_keys_key_array_24, 7},
{nasm_main_keys_key_array_25, 5},
{0, 0},
{0, 0},
{nasm_main_keys_key_array_28, 19},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{nasm_main_keys_key_array_33, 5},
{nasm_main_keys_key_array_34, 6},
{nasm_main_keys_key_array_35, 9},
{0, 0},
{0, 0},
{nasm_main_keys_key_array_38, 2},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{nasm_main_keys_key_array_49, 3},
{0, 0},
{0, 0},
{0, 0},
{nasm_main_keys_key_array_53, 3},
{nasm_main_keys_key_array_54, 4},
{nasm_main_keys_key_array_55, 4},
{nasm_main_keys_key_array_56, 2},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{nasm_main_keys_key_array_61, 3},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{nasm_main_keys_key_array_77, 3},
{0, 0},
{0, 0},
{0, 0},
{nasm_main_keys_key_array_81, 6},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{nasm_main_keys_key_array_88, 4},
{nasm_main_keys_key_array_89, 3},
{nasm_main_keys_key_array_90, 3},
{nasm_main_keys_key_array_91, 3},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{nasm_main_keys_key_array_100, 3},
{0, 0},
{0, 0},
{nasm_main_keys_key_array_103, 3},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{nasm_main_keys_key_array_108, 8},
{nasm_main_keys_key_array_109, 2},
{0, 0},
{0, 0},
{0, 0},
{nasm_main_keys_key_array_113, 2},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{nasm_main_keys_key_array_118, 3},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{nasm_main_keys_key_array_132, 12},
{0, 0},
{nasm_main_keys_key_array_134, 3},
{0, 0},
{nasm_main_keys_key_array_136, 4},
{nasm_main_keys_key_array_137, 4},
{nasm_main_keys_key_array_138, 4},
{nasm_main_keys_key_array_139, 4},
{0, 0},
{0, 0},
{nasm_main_keys_key_array_142, 4},
{0, 0},
{nasm_main_keys_key_array_144, 6},
{nasm_main_keys_key_array_145, 4},
{0, 0},
{0, 0},
{nasm_main_keys_key_array_148, 4},
{nasm_main_keys_key_array_149, 4},
{nasm_main_keys_key_array_150, 4},
{nasm_main_keys_key_array_151, 4},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{nasm_main_keys_key_array_163, 4},
{0, 0},
{nasm_main_keys_key_array_165, 3},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{nasm_main_keys_key_array_172, 12},
{nasm_main_keys_key_array_173, 4},
{0, 0},
{0, 0},
{0, 0},
{nasm_main_keys_key_array_177, 3},
{0, 0},
{0, 0},
{0, 0},
{nasm_main_keys_key_array_181, 3},
{nasm_main_keys_key_array_182, 3},
{nasm_main_keys_key_array_183, 3},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{nasm_main_keys_key_array_189, 4},
{0, 0},
{0, 0},
{0, 0},
{nasm_main_keys_key_array_193, 4},
{0, 0},
{0, 0},
{nasm_main_keys_key_array_196, 17},
{nasm_main_keys_key_array_197, 2},
{0, 0},
{0, 0},
{0, 0},
{nasm_main_keys_key_array_201, 3},
{0, 0},
{0, 0},
{0, 0},
{nasm_main_keys_key_array_205, 6},
{nasm_main_keys_key_array_206, 2},
{0, 0},
{0, 0},
{nasm_main_keys_key_array_209, 5},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{nasm_main_keys_key_array_216, 3},
{0, 0},
{0, 0},
{0, 0},
{nasm_main_keys_key_array_220, 17},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{nasm_main_keys_key_array_229, 2},
{nasm_main_keys_key_array_230, 3},
{0, 0},
{0, 0},
{nasm_main_keys_key_array_233, 2},
{nasm_main_keys_key_array_234, 3},
{nasm_main_keys_key_array_235, 6},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{nasm_main_keys_key_array_240, 2},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{nasm_main_keys_key_array_245, 2},
{nasm_main_keys_key_array_246, 3},
{0, 0},
{nasm_main_keys_key_array_248, 3},
{nasm_main_keys_key_array_249, 3},
{nasm_main_keys_key_array_250, 6},
{nasm_main_keys_key_array_251, 3},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{nasm_main_keys_key_array_260, 3},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{nasm_main_keys_key_array_267, 3},
{0, 0},
{0, 0},
{nasm_main_keys_key_array_270, 3},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{nasm_main_keys_key_array_283, 7},
{0, 0},
{nasm_main_keys_key_array_285, 3},
{nasm_main_keys_key_array_286, 7},
{nasm_main_keys_key_array_287, 4},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{nasm_main_keys_key_array_301, 3},
{0, 0},
{0, 0},
{0, 0},
{nasm_main_keys_key_array_305, 6},
{0, 0},
{nasm_main_keys_key_array_307, 3},
{nasm_main_keys_key_array_308, 3},
{nasm_main_keys_key_array_309, 3},
{nasm_main_keys_key_array_310, 3},
{nasm_main_keys_key_array_311, 3},
{0, 0},
{nasm_main_keys_key_array_313, 4},
{0, 0},
{nasm_main_keys_key_array_315, 4},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{nasm_main_keys_key_array_320, 4},
{nasm_main_keys_key_array_321, 2},
{nasm_main_keys_key_array_322, 4},
{nasm_main_keys_key_array_323, 4},
{nasm_main_keys_key_array_324, 4},
{0, 0},
{nasm_main_keys_key_array_326, 4},
{0, 0},
{0, 0},
{nasm_main_keys_key_array_329, 4},
{0, 0},
{0, 0},
{nasm_main_keys_key_array_332, 4},
{nasm_main_keys_key_array_333, 4},
{nasm_main_keys_key_array_334, 4},
{nasm_main_keys_key_array_335, 4},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{nasm_main_keys_key_array_341, 6},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{nasm_main_keys_key_array_349, 2},
{0, 0},
{0, 0},
{0, 0},
{nasm_main_keys_key_array_353, 5},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{nasm_main_keys_key_array_369, 2},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{nasm_main_keys_key_array_381, 3},
{0, 0},
{0, 0},
{0, 0},
{nasm_main_keys_key_array_385, 2},
{0, 0},
{0, 0},
{nasm_main_keys_key_array_388, 5},
{nasm_main_keys_key_array_389, 16},
{nasm_main_keys_key_array_390, 2},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{nasm_main_keys_key_array_396, 8},
{nasm_main_keys_key_array_397, 8},
{nasm_main_keys_key_array_398, 3},
{0, 0},
{nasm_main_keys_key_array_400, 6},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{nasm_main_keys_key_array_405, 3},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{nasm_main_keys_key_array_412, 14},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{nasm_main_keys_key_array_422, 2},
{0, 0},
{nasm_main_keys_key_array_424, 6},
{nasm_main_keys_key_array_425, 5},
{nasm_main_keys_key_array_426, 5},
{nasm_main_keys_key_array_427, 5},
{0, 0},
{nasm_main_keys_key_array_429, 2},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{nasm_main_keys_key_array_434, 9},
{nasm_main_keys_key_array_435, 5},
{0, 0},
{nasm_main_keys_key_array_437, 5},
{nasm_main_keys_key_array_438, 5},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{nasm_main_keys_key_array_448, 3},
{nasm_main_keys_key_array_449, 3},
{nasm_main_keys_key_array_450, 3},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{nasm_main_keys_key_array_456, 8},
{nasm_main_keys_key_array_457, 4},
{0, 0},
{nasm_main_keys_key_array_459, 3},
{nasm_main_keys_key_array_460, 3},
{nasm_main_keys_key_array_461, 3},
{nasm_main_keys_key_array_462, 3},
{nasm_main_keys_key_array_463, 3},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{nasm_main_keys_key_array_468, 12},
{0, 0},
{0, 0},
{nasm_main_keys_key_array_471, 4},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{nasm_main_keys_key_array_476, 8},
{nasm_main_keys_key_array_477, 8},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{nasm_main_keys_key_array_514, 6},
{0, 0},
{0, 0},
{nasm_main_keys_key_array_517, 6},
{nasm_main_keys_key_array_518, 3},
{0, 0},
{0, 0},
{nasm_main_keys_key_array_521, 4},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{nasm_main_keys_key_array_536, 3},
{nasm_main_keys_key_array_537, 3},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{nasm_main_keys_key_array_549, 2},
{nasm_main_keys_key_array_550, 2},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{nasm_main_keys_key_array_561, 3},
{0, 0},
{0, 0},
{nasm_main_keys_key_array_564, 12},
{nasm_main_keys_key_array_565, 14},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{nasm_main_keys_key_array_574, 5},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{nasm_main_keys_key_array_585, 7},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{nasm_main_keys_key_array_597, 7},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{nasm_main_keys_key_array_604, 8},
{0, 0},
{0, 0},
{0, 0},
{nasm_main_keys_key_array_608, 4},
{nasm_main_keys_key_array_609, 5},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{nasm_main_keys_key_array_625, 6},
{0, 0},
{0, 0},
{0, 0},
{nasm_main_keys_key_array_629, 5},
{nasm_main_keys_key_array_630, 4},
{0, 0},
{0, 0},
{nasm_main_keys_key_array_633, 5},
{0, 0},
{0, 0},
{nasm_main_keys_key_array_636, 20},
{0, 0},
{0, 0},
{nasm_main_keys_key_array_639, 4},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{nasm_main_keys_key_array_653, 3},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{nasm_main_keys_key_array_660, 14},
{0, 0},
{0, 0},
{0, 0},
{nasm_main_keys_key_array_664, 5},
{nasm_main_keys_key_array_665, 5},
{0, 0},
{nasm_main_keys_key_array_667, 5},
{nasm_main_keys_key_array_668, 4},
{nasm_main_keys_key_array_669, 5},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{nasm_main_keys_key_array_674, 5},
{0, 0},
{0, 0},
{nasm_main_keys_key_array_677, 5},
{nasm_main_keys_key_array_678, 5},
{0, 0},
{0, 0},
{nasm_main_keys_key_array_681, 4},
{0, 0},
{0, 0},
{0, 0},
{nasm_main_keys_key_array_685, 3},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{nasm_main_keys_key_array_693, 5},
{0, 0},
{nasm_main_keys_key_array_695, 4},
{0, 0},
{nasm_main_keys_key_array_697, 7},
{0, 0},
{0, 0},
{nasm_main_keys_key_array_700, 2},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{nasm_main_keys_key_array_707, 5},
{nasm_main_keys_key_array_708, 12},
{0, 0},
{0, 0},
{0, 0},
{nasm_main_keys_key_array_712, 5},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{nasm_main_keys_key_array_723, 6},
{0, 0},
{0, 0},
{0, 0},
{nasm_main_keys_key_array_727, 4},
{nasm_main_keys_key_array_728, 2},
{nasm_main_keys_key_array_729, 2},
{0, 0},
{0, 0},
{0, 0},
{nasm_main_keys_key_array_733, 3},
{0, 0},
{0, 0},
{nasm_main_keys_key_array_736, 3},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{nasm_main_keys_key_array_746, 8},
{0, 0},
{nasm_main_keys_key_array_748, 4},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{nasm_main_keys_key_array_754, 3},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{nasm_main_keys_key_array_761, 5},
{0, 0},
{0, 0},
{nasm_main_keys_key_array_764, 16},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{nasm_main_keys_key_array_781, 5},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{nasm_main_keys_key_array_786, 3},
{0, 0},
{0, 0},
{nasm_main_keys_key_array_789, 3},
{nasm_main_keys_key_array_790, 3},
{0, 0},
{nasm_main_keys_key_array_792, 3},
{nasm_main_keys_key_array_793, 3},
{0, 0},
{nasm_main_keys_key_array_795, 3},
{0, 0},
{nasm_main_keys_key_array_797, 4},
{0, 0},
{0, 0},
{0, 0},
{nasm_main_keys_key_array_801, 2},
{nasm_main_keys_key_array_802, 5},
{0, 0},
{nasm_main_keys_key_array_804, 2},
{0, 0},
{0, 0},
{0, 0},
};
Lexeme_Table_Value nasm_main_keys_value_array[808] = {
{0, 0},
{4, TokenNasmKind_rax},
{0, 0},
{0, 0},
{4, TokenNasmKind_r11w},
{4, TokenNasmKind_ymm7h},
{0, 0},
{0, 0},
{0, 0},
{4, TokenNasmKind_dh},
{0, 0},
{4, TokenNasmKind_r11b},
{0, 0},
{4, TokenNasmKind_dl},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{4, TokenNasmKind_alignb},
{0, 0},
{0, 0},
{0, 0},
{4, TokenNasmKind_extern},
{4, TokenNasmKind_warning},
{4, TokenNasmKind_struc},
{0, 0},
{0, 0},
{4, TokenNasmKind___NASM_VERSION_ID__},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{4, TokenNasmKind_ymm9h},
{4, TokenNasmKind_ymm11h},
{4, TokenNasmKind_sectalign},
{0, 0},
{0, 0},
{4, TokenNasmKind_di},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{4, TokenNasmKind_eax},
{0, 0},
{0, 0},
{0, 0},
{4, TokenNasmKind_ebp},
{4, TokenNasmKind_r14d},
{4, TokenNasmKind_r14b},
{4, TokenNasmKind_es},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{4, TokenNasmKind_ebx},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{4, TokenNasmKind_rbp},
{0, 0},
{0, 0},
{0, 0},
{4, TokenNasmKind_import},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{4, TokenNasmKind_r14w},
{4, TokenNasmKind_tr7},
{4, TokenNasmKind_tr4},
{4, TokenNasmKind_tr5},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{4, TokenNasmKind_tr3},
{0, 0},
{0, 0},
{4, TokenNasmKind_tr6},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{4, TokenNasmKind___TIME__},
{4, TokenNasmKind_bh},
{0, 0},
{0, 0},
{0, 0},
{4, TokenNasmKind_bl},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{4, TokenNasmKind_esi},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{4, TokenNasmKind___UTC_DATE__},
{0, 0},
{4, TokenNasmKind_edi},
{0, 0},
{4, TokenNasmKind_xmm3},
{4, TokenNasmKind_xmm0},
{4, TokenNasmKind_xmm5},
{4, TokenNasmKind_xmm2},
{0, 0},
{0, 0},
{4, TokenNasmKind_xmm1},
{0, 0},
{4, TokenNasmKind_rflags},
{4, TokenNasmKind_xmm8},
{0, 0},
{0, 0},
{4, TokenNasmKind_xmm7},
{4, TokenNasmKind_xmm4},
{4, TokenNasmKind_xmm9},
{4, TokenNasmKind_xmm6},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{4, TokenNasmKind_r15b},
{0, 0},
{4, TokenNasmKind_rsp},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{4, TokenNasmKind___DATE_NUM__},
{4, TokenNasmKind_r15w},
{0, 0},
{0, 0},
{0, 0},
{4, TokenNasmKind_edx},
{0, 0},
{0, 0},
{0, 0},
{4, TokenNasmKind_rbx},
{4, TokenNasmKind_r8d},
{4, TokenNasmKind_r8b},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{4, TokenNasmKind_r15d},
{0, 0},
{0, 0},
{0, 0},
{4, TokenNasmKind_list},
{0, 0},
{0, 0},
{4, TokenNasmKind___OUTPUT_FORMAT__},
{4, TokenNasmKind_bx},
{0, 0},
{0, 0},
{0, 0},
{4, TokenNasmKind_map},
{0, 0},
{0, 0},
{0, 0},
{4, TokenNasmKind_global},
{4, TokenNasmKind_bp},
{0, 0},
{0, 0},
{4, TokenNasmKind_ymm8h},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{4, TokenNasmKind_r8w},
{0, 0},
{0, 0},
{0, 0},
{4, TokenNasmKind___NASM_SUBMINOR__},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{4, TokenNasmKind_ch},
{4, TokenNasmKind_bpl},
{0, 0},
{0, 0},
{4, TokenNasmKind_cl},
{4, TokenNasmKind_eip},
{4, TokenNasmKind_ymm14h},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{4, TokenNasmKind_cs},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{4, TokenNasmKind_cx},
{4, TokenNasmKind_r9d},
{0, 0},
{4, TokenNasmKind_cr7},
{4, TokenNasmKind_cr4},
{4, TokenNasmKind_ymm15h},
{4, TokenNasmKind_cr5},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{4, TokenNasmKind_r9w},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{4, TokenNasmKind_r9b},
{0, 0},
{0, 0},
{4, TokenNasmKind_rsi},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{4, TokenNasmKind_section},
{0, 0},
{4, TokenNasmKind_esp},
{4, TokenNasmKind_library},
{4, TokenNasmKind_gdtr},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{4, TokenNasmKind_cr8},
{0, 0},
{0, 0},
{0, 0},
{4, TokenNasmKind_ymm10h},
{0, 0},
{4, TokenNasmKind_cr2},
{4, TokenNasmKind_cr3},
{4, TokenNasmKind_cr0},
{4, TokenNasmKind_cr1},
{4, TokenNasmKind_cr6},
{0, 0},
{4, TokenNasmKind_r12d},
{0, 0},
{4, TokenNasmKind_r12b},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{4, TokenNasmKind_ymm3},
{4, TokenNasmKind_ip},
{4, TokenNasmKind_ymm0},
{4, TokenNasmKind_ymm5},
{4, TokenNasmKind_ymm2},
{0, 0},
{4, TokenNasmKind_ymm1},
{0, 0},
{0, 0},
{4, TokenNasmKind_ymm8},
{0, 0},
{0, 0},
{4, TokenNasmKind_ymm7},
{4, TokenNasmKind_ymm4},
{4, TokenNasmKind_ymm9},
{4, TokenNasmKind_ymm6},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{4, TokenNasmKind_ymm12h},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{4, TokenNasmKind_al},
{0, 0},
{0, 0},
{0, 0},
{4, TokenNasmKind_ymm1h},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{4, TokenNasmKind_ax},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{4, TokenNasmKind_ipl},
{0, 0},
{0, 0},
{0, 0},
{4, TokenNasmKind_ah},
{0, 0},
{0, 0},
{4, TokenNasmKind_debug},
{4, TokenNasmKind___UTC_TIME_NUM__},
{4, TokenNasmKind_at},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{4, TokenNasmKind___BITS__},
{4, TokenNasmKind___DATE__},
{4, TokenNasmKind_spl},
{0, 0},
{4, TokenNasmKind_istruc},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{4, TokenNasmKind_ecx},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{4, TokenNasmKind___NASM_MINOR__},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{4, TokenNasmKind_si},
{0, 0},
{4, TokenNasmKind_eflags},
{4, TokenNasmKind_ymm13},
{4, TokenNasmKind_ymm10},
{4, TokenNasmKind_ymm12},
{0, 0},
{4, TokenNasmKind_sp},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{4, TokenNasmKind_uppercase},
{4, TokenNasmKind_ymm15},
{0, 0},
{4, TokenNasmKind_ymm14},
{4, TokenNasmKind_ymm11},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{4, TokenNasmKind_dr7},
{4, TokenNasmKind_dr4},
{4, TokenNasmKind_dr5},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{4, TokenNasmKind_endstruc},
{4, TokenNasmKind_r12w},
{0, 0},
{4, TokenNasmKind_dr2},
{4, TokenNasmKind_dr3},
{4, TokenNasmKind_dr0},
{4, TokenNasmKind_dr1},
{4, TokenNasmKind_dr6},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{4, TokenNasmKind___TIME_NUM__},
{0, 0},
{0, 0},
{4, TokenNasmKind_idtr},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{4, TokenNasmKind___LINE__},
{4, TokenNasmKind___PASS__},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{4, TokenNasmKind_module},
{0, 0},
{0, 0},
{4, TokenNasmKind_ymm13h},
{4, TokenNasmKind_rdi},
{0, 0},
{0, 0},
{4, TokenNasmKind_iend},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{4, TokenNasmKind_org},
{4, TokenNasmKind_rdx},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{4, TokenNasmKind_r8},
{4, TokenNasmKind_r9},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{4, TokenNasmKind_rip},
{0, 0},
{0, 0},
{4, TokenNasmKind___UTC_TIME__},
{4, TokenNasmKind___POSIX_TIME__},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{4, TokenNasmKind_osabi},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{4, TokenNasmKind_segment},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{4, TokenNasmKind_default},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{4, TokenNasmKind___FILE__},
{0, 0},
{0, 0},
{0, 0},
{4, TokenNasmKind_r10w},
{4, TokenNasmKind_group},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{4, TokenNasmKind_export},
{0, 0},
{0, 0},
{0, 0},
{4, TokenNasmKind_float},
{4, TokenNasmKind_r10d},
{0, 0},
{0, 0},
{4, TokenNasmKind_ymm5h},
{0, 0},
{0, 0},
{4, TokenNasmKind____NASM_PATCHLEVEL__},
{0, 0},
{0, 0},
{4, TokenNasmKind_r10b},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{4, TokenNasmKind_sil},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{4, TokenNasmKind___NASM_MAJOR__},
{0, 0},
{0, 0},
{0, 0},
{4, TokenNasmKind_xmm13},
{4, TokenNasmKind_xmm10},
{0, 0},
{4, TokenNasmKind_xmm12},
{4, TokenNasmKind_r13w},
{4, TokenNasmKind_ymm6h},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{4, TokenNasmKind_xmm15},
{0, 0},
{0, 0},
{4, TokenNasmKind_xmm14},
{4, TokenNasmKind_xmm11},
{0, 0},
{0, 0},
{4, TokenNasmKind_r13d},
{0, 0},
{0, 0},
{0, 0},
{4, TokenNasmKind_rcx},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{4, TokenNasmKind_ymm2h},
{0, 0},
{4, TokenNasmKind_r13b},
{0, 0},
{4, TokenNasmKind_safeseh},
{0, 0},
{0, 0},
{4, TokenNasmKind_fs},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{4, TokenNasmKind_align},
{4, TokenNasmKind___NASM_VER__},
{0, 0},
{0, 0},
{0, 0},
{4, TokenNasmKind_flags},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{4, TokenNasmKind_common},
{0, 0},
{0, 0},
{0, 0},
{4, TokenNasmKind_ldtr},
{4, TokenNasmKind_ss},
{4, TokenNasmKind_gs},
{0, 0},
{0, 0},
{0, 0},
{4, TokenNasmKind_dil},
{0, 0},
{0, 0},
{4, TokenNasmKind_xss},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{4, TokenNasmKind_absolute},
{0, 0},
{4, TokenNasmKind_bits},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{4, TokenNasmKind_cpu},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{4, TokenNasmKind_ymm0h},
{0, 0},
{0, 0},
{4, TokenNasmKind___UTC_DATE_NUM__},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{4, TokenNasmKind_ymm3h},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{4, TokenNasmKind_r15},
{0, 0},
{0, 0},
{4, TokenNasmKind_r14},
{4, TokenNasmKind_r11},
{0, 0},
{4, TokenNasmKind_r13},
{4, TokenNasmKind_r10},
{0, 0},
{4, TokenNasmKind_r12},
{0, 0},
{4, TokenNasmKind_r11d},
{0, 0},
{0, 0},
{0, 0},
{4, TokenNasmKind_dx},
{4, TokenNasmKind_ymm4h},
{0, 0},
{4, TokenNasmKind_ds},
{0, 0},
{0, 0},
{0, 0},
};
i32 nasm_main_keys_slot_count = 808;
u64 nasm_main_keys_seed = 0x6c44e4356713ce8d;
u64 nasm_pp_directives_hash_array[179] = {
0x16201b72d9b8e415,0xde3ab5b4564db049,0x0000000000000000,0x0000000000000000,
0xd64332a11f29c723,0xa0516a92da9281c7,0x0000000000000000,0x00be035a67c31a95,
0x16201b72ceb826b1,0x00b92ef77d8c5ce3,0x00beac34e2e3a6fb,0x0000000000000000,
0x0000000000000000,0xd64332bbe639f4f1,0xde3ab5bae4827ce3,0x0000000000000000,
0x0000000000000000,0x0000000000000000,0x0000000000000000,0xde3ab5b47a26802d,
0xde3ab3217b3146e3,0x16201b72ab0a2945,0x16201b72ab0a2515,0xde2dd528defc5a45,
0x0000000000000000,0x0000000000000000,0x0000000000000000,0x361f8126e190cbc7,
0x16201b72a8e4fce3,0x0000000000000000,0x0000000000000000,0xde3ab5bae0149a95,
0x00be03f27f29b245,0x361f8126e1851859,0x361f8126e1fdd603,0x0000000000000000,
0xcd2685e89637659d,0xde3ab5bcbd84af9d,0x0000000000000000,0xd64332b934d44145,
0xcd2685dad3f99a95,0xde3ab3217b353471,0xd64332b934d40471,0x16201b72a2219061,
0x0000000000000000,0x16201b72cea1153d,0x00beac34e2e55b71,0xd64332bbe626c245,
0xd64332b90bc66149,0x0000000000000000,0x0000000000000000,0x0000000000000000,
0x0000000000000000,0x0000000000000000,0x0000000000000000,0xfc42b7dfe989416f,
0x0000000000000000,0xfc42b7dfe98ad6fd,0x0000000000000000,0x0000000000000000,
0x0000000000000000,0xde3ab5b197c527a1,0x0000000000000000,0xd64332b934d4e4fb,
0xd64332b934d4e395,0xd64332b9182a9ce3,0x0000000000000000,0x361f8126e184da41,
0xfc42b7dfe9897e51,0x0000000000000000,0x00beac34e2e3e575,0xfc42b7dfe989abc7,
0x00beac34e2d7f049,0xde3ab5bea617677f,0x0000000000000000,0x0000000000000000,
0xd2502abaa9569a95,0xde3ab3df0157c02f,0x0000000000000000,0x00beac34e2dd51c5,
0x0000000000000000,0xd2502aba9d0b7a49,0xfc42b7dfe98aa78b,0x361f8126e184c33d,
0x0000000000000000,0x0000000000000000,0xd64332bbe639077f,0xd64332a7d06d0b9d,
0xde3ab3217b31e0fb,0x0000000000000000,0x00be0359e1d8059d,0x04cafbc5fa8076bf,
0x0000000000000000,0x0000000000000000,0xd64332a66fa680e3,0x16201b72ab6e92f1,
0x0000000000000000,0x0000000000000000,0x0000000000000000,0xde3ab5bea629b245,
0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000,
0x0000000000000000,0xd64332a63d5db6e1,0xd102ac2fb2c1bf8d,0x0000000000000000,
0xd2502aba9d3bbce3,0x0000000000000000,0xde3ab5b5e77d78e3,0xd3bec6f064104923,
0x0000000000000000,0x0000000000000000,0x00be035a4a44fce3,0xd64332b934d4fcf5,
0x0000000000000000,0xde3ab3217b31eb95,0x0000000000000000,0x0000000000000000,
0xd64332a62d415871,0x0000000000000000,0x0000000000000000,0x0000000000000000,
0xcd2685daf422fce3,0x0000000000000000,0x0000000000000000,0x0000000000000000,
0x16201b72ab0a337b,0x0000000000000000,0x0000000000000000,0x0000000000000000,
0xde3ab5bea61700f1,0xde3ab0f1dac65ce3,0x0000000000000000,0x0000000000000000,
0x0000000000000000,0x85bee84ab288db85,0x0000000000000000,0x00beac34e2e3b095,
0xde3ab3217b356945,0x16201b72ab0a1e8d,0xde3ab3217b314cf5,0xd64332a11a3c85ef,
0x0000000000000000,0x0000000000000000,0xd2502abad183e59d,0x16201b72ce94b62d,
0x361f8126e1f44035,0x0000000000000000,0x0000000000000000,0x361f8126e1b8d6cf,
0xde3ab536b1b601c7,0x16201b72d68c840b,0x0000000000000000,0xd64332b8fe271c2d,
0x0000000000000000,0x16201b72ab05db23,0x0000000000000000,0x0000000000000000,
0x00bef94ed53df923,0xd64332a7d06d0003,0x0000000000000000,0xde3ab3217b319c0d,
0x16201b72ce0aeb5b,0x0000000000000000,0x0000000000000000,0x0000000000000000,
0x0000000000000000,0x0000000000000000,0x0000000000000000,0x16201b72ab05d0b5,
0x00beac34e2e38d0d,0x0000000000000000,0x0000000000000000,0xd64332bbe516fc67,
0x0000000000000000,0x0000000000000000,0xd64332b934d52c0d,
};
u8 nasm_pp_directives_key_array_0[] = {0x75,0x6e,0x64,0x65,0x66,};
u8 nasm_pp_directives_key_array_1[] = {0x69,0x66,0x6e,0x69,0x64,0x6e,0x69,};
u8 nasm_pp_directives_key_array_4[] = {0x65,0x6c,0x69,0x66,0x69,0x64,};
u8 nasm_pp_directives_key_array_5[] = {0x65,0x6e,0x64,0x63,0x6f,0x6d,0x6d,0x65,0x6e,0x74,};
u8 nasm_pp_directives_key_array_7[] = {0x69,0x66,0x6e,0x65,0x6d,0x70,0x74,0x79,};
u8 nasm_pp_directives_key_array_8[] = {0x65,0x72,0x72,0x6f,0x72,};
u8 nasm_pp_directives_key_array_9[] = {0x75,0x6e,0x69,0x6d,0x61,0x63,0x72,0x6f,};
u8 nasm_pp_directives_key_array_10[] = {0x65,0x6c,0x69,0x66,0x6e,0x63,0x74,0x78,};
u8 nasm_pp_directives_key_array_13[] = {0x64,0x65,0x66,0x73,0x74,0x72,};
u8 nasm_pp_directives_key_array_14[] = {0x69,0x66,0x6d,0x61,0x63,0x72,0x6f,};
u8 nasm_pp_directives_key_array_19[] = {0x69,0x61,0x73,0x73,0x69,0x67,0x6e,};
u8 nasm_pp_directives_key_array_20[] = {0x65,0x6c,0x69,0x66,0x6e,0x69,0x64,};
u8 nasm_pp_directives_key_array_21[] = {0x69,0x66,0x65,0x6e,0x76,};
u8 nasm_pp_directives_key_array_22[] = {0x69,0x66,0x64,0x65,0x66,};
u8 nasm_pp_directives_key_array_23[] = {0x78,0x64,0x65,0x66,0x69,0x6e,0x65,};
u8 nasm_pp_directives_key_array_27[] = {0x72,0x65,0x70,0x6c,};
u8 nasm_pp_directives_key_array_28[] = {0x6d,0x61,0x63,0x72,0x6f,};
u8 nasm_pp_directives_key_array_31[] = {0x69,0x66,0x65,0x6d,0x70,0x74,0x79,};
u8 nasm_pp_directives_key_array_32[] = {0x69,0x78,0x64,0x65,0x66,0x69,0x6e,0x65,};
u8 nasm_pp_directives_key_array_33[] = {0x65,0x6e,0x64,0x6d,};
u8 nasm_pp_directives_key_array_34[] = {0x69,0x66,0x69,0x64,};
u8 nasm_pp_directives_key_array_36[] = {0x65,0x6c,0x69,0x66,0x6e,0x74,0x6f,0x6b,0x65,0x6e,};
u8 nasm_pp_directives_key_array_37[] = {0x69,0x66,0x74,0x6f,0x6b,0x65,0x6e,};
u8 nasm_pp_directives_key_array_39[] = {0x69,0x66,0x6e,0x65,0x6e,0x76,};
u8 nasm_pp_directives_key_array_40[] = {0x65,0x6c,0x69,0x66,0x6e,0x65,0x6d,0x70,0x74,0x79,};
u8 nasm_pp_directives_key_array_41[] = {0x65,0x6c,0x69,0x66,0x73,0x74,0x72,};
u8 nasm_pp_directives_key_array_42[] = {0x69,0x66,0x6e,0x73,0x74,0x72,};
u8 nasm_pp_directives_key_array_43[] = {0x63,0x6c,0x65,0x61,0x72,};
u8 nasm_pp_directives_key_array_45[] = {0x65,0x6e,0x64,0x69,0x66,};
u8 nasm_pp_directives_key_array_46[] = {0x65,0x6c,0x69,0x66,0x6e,0x73,0x74,0x72,};
u8 nasm_pp_directives_key_array_47[] = {0x64,0x65,0x66,0x69,0x6e,0x65,};
u8 nasm_pp_directives_key_array_48[] = {0x69,0x66,0x69,0x64,0x6e,0x69,};
u8 nasm_pp_directives_key_array_55[] = {0x72,0x65,0x70,};
u8 nasm_pp_directives_key_array_57[] = {0x69,0x66,0x6e,};
u8 nasm_pp_directives_key_array_61[] = {0x69,0x6e,0x63,0x6c,0x75,0x64,0x65,};
u8 nasm_pp_directives_key_array_63[] = {0x69,0x66,0x6e,0x63,0x74,0x78,};
u8 nasm_pp_directives_key_array_64[] = {0x69,0x66,0x6e,0x64,0x65,0x66,};
u8 nasm_pp_directives_key_array_65[] = {0x69,0x6d,0x61,0x63,0x72,0x6f,};
u8 nasm_pp_directives_key_array_67[] = {0x65,0x6c,0x73,0x65,};
u8 nasm_pp_directives_key_array_68[] = {0x75,0x73,0x65,};
u8 nasm_pp_directives_key_array_70[] = {0x65,0x6c,0x69,0x66,0x6e,0x6e,0x75,0x6d,};
u8 nasm_pp_directives_key_array_71[] = {0x70,0x6f,0x70,};
u8 nasm_pp_directives_key_array_72[] = {0x65,0x6c,0x69,0x66,0x69,0x64,0x6e,0x69,};
u8 nasm_pp_directives_key_array_73[] = {0x69,0x64,0x65,0x66,0x74,0x6f,0x6b,};
u8 nasm_pp_directives_key_array_76[] = {0x65,0x6c,0x69,0x66,0x65,0x6d,0x70,0x74,0x79,};
u8 nasm_pp_directives_key_array_77[] = {0x65,0x78,0x69,0x74,0x72,0x65,0x70,};
u8 nasm_pp_directives_key_array_79[] = {0x65,0x6c,0x69,0x66,0x6e,0x65,0x6e,0x76,};
u8 nasm_pp_directives_key_array_81[] = {0x65,0x6c,0x69,0x66,0x6e,0x69,0x64,0x6e,0x69,};
u8 nasm_pp_directives_key_array_82[] = {0x61,0x72,0x67,};
u8 nasm_pp_directives_key_array_83[] = {0x65,0x6c,0x69,0x66,};
u8 nasm_pp_directives_key_array_86[] = {0x64,0x65,0x66,0x74,0x6f,0x6b,};
u8 nasm_pp_directives_key_array_87[] = {0x73,0x74,0x72,0x6c,0x65,0x6e,};
u8 nasm_pp_directives_key_array_88[] = {0x65,0x6c,0x69,0x66,0x63,0x74,0x78,};
u8 nasm_pp_directives_key_array_90[] = {0x69,0x66,0x6e,0x74,0x6f,0x6b,0x65,0x6e,};
u8 nasm_pp_directives_key_array_91[] = {0x70,0x61,0x74,0x68,0x73,0x65,0x61,0x72,0x63,0x68,};
u8 nasm_pp_directives_key_array_94[] = {0x72,0x6d,0x61,0x63,0x72,0x6f,};
u8 nasm_pp_directives_key_array_95[] = {0x69,0x66,0x73,0x74,0x72,};
u8 nasm_pp_directives_key_array_99[] = {0x69,0x64,0x65,0x66,0x69,0x6e,0x65,};
u8 nasm_pp_directives_key_array_105[] = {0x72,0x6f,0x74,0x61,0x74,0x65,};
u8 nasm_pp_directives_key_array_106[] = {0x73,0x74,0x61,0x63,0x6b,0x73,0x69,0x7a,0x65,};
u8 nasm_pp_directives_key_array_108[] = {0x65,0x6c,0x69,0x66,0x6d,0x61,0x63,0x72,0x6f,};
u8 nasm_pp_directives_key_array_110[] = {0x69,0x72,0x6d,0x61,0x63,0x72,0x6f,};
u8 nasm_pp_directives_key_array_111[] = {0x65,0x78,0x69,0x74,0x6d,0x61,0x63,0x72,0x6f,};
u8 nasm_pp_directives_key_array_114[] = {0x69,0x66,0x6e,0x6d,0x61,0x63,0x72,0x6f,};
u8 nasm_pp_directives_key_array_115[] = {0x69,0x66,0x6e,0x6e,0x75,0x6d,};
u8 nasm_pp_directives_key_array_117[] = {0x65,0x6c,0x69,0x66,0x64,0x65,0x66,};
u8 nasm_pp_directives_key_array_120[] = {0x73,0x75,0x62,0x73,0x74,0x72,};
u8 nasm_pp_directives_key_array_124[] = {0x65,0x6c,0x69,0x66,0x6e,0x6d,0x61,0x63,0x72,0x6f,};
u8 nasm_pp_directives_key_array_128[] = {0x69,0x66,0x63,0x74,0x78,};
u8 nasm_pp_directives_key_array_132[] = {0x69,0x64,0x65,0x66,0x73,0x74,0x72,};
u8 nasm_pp_directives_key_array_133[] = {0x75,0x6e,0x6d,0x61,0x63,0x72,0x6f,};
u8 nasm_pp_directives_key_array_137[] = {0x69,0x66,};
u8 nasm_pp_directives_key_array_139[] = {0x65,0x6c,0x69,0x66,0x6e,0x64,0x65,0x66,};
u8 nasm_pp_directives_key_array_140[] = {0x65,0x6c,0x69,0x66,0x65,0x6e,0x76,};
u8 nasm_pp_directives_key_array_141[] = {0x69,0x66,0x69,0x64,0x6e,};
u8 nasm_pp_directives_key_array_142[] = {0x65,0x6c,0x69,0x66,0x6e,0x75,0x6d,};
u8 nasm_pp_directives_key_array_143[] = {0x65,0x6e,0x64,0x72,0x65,0x70,};
u8 nasm_pp_directives_key_array_146[] = {0x65,0x6c,0x69,0x66,0x74,0x6f,0x6b,0x65,0x6e,};
u8 nasm_pp_directives_key_array_147[] = {0x65,0x6c,0x69,0x66,0x6e,};
u8 nasm_pp_directives_key_array_148[] = {0x6c,0x69,0x6e,0x65,};
u8 nasm_pp_directives_key_array_151[] = {0x70,0x75,0x73,0x68,};
u8 nasm_pp_directives_key_array_152[] = {0x63,0x6f,0x6d,0x6d,0x65,0x6e,0x74,};
u8 nasm_pp_directives_key_array_153[] = {0x6c,0x6f,0x63,0x61,0x6c,};
u8 nasm_pp_directives_key_array_155[] = {0x61,0x73,0x73,0x69,0x67,0x6e,};
u8 nasm_pp_directives_key_array_157[] = {0x69,0x66,0x6e,0x69,0x64,};
u8 nasm_pp_directives_key_array_160[] = {0x65,0x6e,0x64,0x6d,0x61,0x63,0x72,0x6f,};
u8 nasm_pp_directives_key_array_161[] = {0x73,0x74,0x72,0x63,0x61,0x74,};
u8 nasm_pp_directives_key_array_163[] = {0x65,0x6c,0x69,0x66,0x69,0x64,0x6e,};
u8 nasm_pp_directives_key_array_164[] = {0x66,0x61,0x74,0x61,0x6c,};
u8 nasm_pp_directives_key_array_171[] = {0x69,0x66,0x6e,0x75,0x6d,};
u8 nasm_pp_directives_key_array_172[] = {0x65,0x6c,0x69,0x66,0x6e,0x69,0x64,0x6e,};
u8 nasm_pp_directives_key_array_175[] = {0x64,0x65,0x70,0x65,0x6e,0x64,};
u8 nasm_pp_directives_key_array_178[] = {0x69,0x66,0x6e,0x69,0x64,0x6e,};
String_Const_u8 nasm_pp_directives_key_array[179] = {
{nasm_pp_directives_key_array_0, 5},
{nasm_pp_directives_key_array_1, 7},
{0, 0},
{0, 0},
{nasm_pp_directives_key_array_4, 6},
{nasm_pp_directives_key_array_5, 10},
{0, 0},
{nasm_pp_directives_key_array_7, 8},
{nasm_pp_directives_key_array_8, 5},
{nasm_pp_directives_key_array_9, 8},
{nasm_pp_directives_key_array_10, 8},
{0, 0},
{0, 0},
{nasm_pp_directives_key_array_13, 6},
{nasm_pp_directives_key_array_14, 7},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{nasm_pp_directives_key_array_19, 7},
{nasm_pp_directives_key_array_20, 7},
{nasm_pp_directives_key_array_21, 5},
{nasm_pp_directives_key_array_22, 5},
{nasm_pp_directives_key_array_23, 7},
{0, 0},
{0, 0},
{0, 0},
{nasm_pp_directives_key_array_27, 4},
{nasm_pp_directives_key_array_28, 5},
{0, 0},
{0, 0},
{nasm_pp_directives_key_array_31, 7},
{nasm_pp_directives_key_array_32, 8},
{nasm_pp_directives_key_array_33, 4},
{nasm_pp_directives_key_array_34, 4},
{0, 0},
{nasm_pp_directives_key_array_36, 10},
{nasm_pp_directives_key_array_37, 7},
{0, 0},
{nasm_pp_directives_key_array_39, 6},
{nasm_pp_directives_key_array_40, 10},
{nasm_pp_directives_key_array_41, 7},
{nasm_pp_directives_key_array_42, 6},
{nasm_pp_directives_key_array_43, 5},
{0, 0},
{nasm_pp_directives_key_array_45, 5},
{nasm_pp_directives_key_array_46, 8},
{nasm_pp_directives_key_array_47, 6},
{nasm_pp_directives_key_array_48, 6},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{nasm_pp_directives_key_array_55, 3},
{0, 0},
{nasm_pp_directives_key_array_57, 3},
{0, 0},
{0, 0},
{0, 0},
{nasm_pp_directives_key_array_61, 7},
{0, 0},
{nasm_pp_directives_key_array_63, 6},
{nasm_pp_directives_key_array_64, 6},
{nasm_pp_directives_key_array_65, 6},
{0, 0},
{nasm_pp_directives_key_array_67, 4},
{nasm_pp_directives_key_array_68, 3},
{0, 0},
{nasm_pp_directives_key_array_70, 8},
{nasm_pp_directives_key_array_71, 3},
{nasm_pp_directives_key_array_72, 8},
{nasm_pp_directives_key_array_73, 7},
{0, 0},
{0, 0},
{nasm_pp_directives_key_array_76, 9},
{nasm_pp_directives_key_array_77, 7},
{0, 0},
{nasm_pp_directives_key_array_79, 8},
{0, 0},
{nasm_pp_directives_key_array_81, 9},
{nasm_pp_directives_key_array_82, 3},
{nasm_pp_directives_key_array_83, 4},
{0, 0},
{0, 0},
{nasm_pp_directives_key_array_86, 6},
{nasm_pp_directives_key_array_87, 6},
{nasm_pp_directives_key_array_88, 7},
{0, 0},
{nasm_pp_directives_key_array_90, 8},
{nasm_pp_directives_key_array_91, 10},
{0, 0},
{0, 0},
{nasm_pp_directives_key_array_94, 6},
{nasm_pp_directives_key_array_95, 5},
{0, 0},
{0, 0},
{0, 0},
{nasm_pp_directives_key_array_99, 7},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{nasm_pp_directives_key_array_105, 6},
{nasm_pp_directives_key_array_106, 9},
{0, 0},
{nasm_pp_directives_key_array_108, 9},
{0, 0},
{nasm_pp_directives_key_array_110, 7},
{nasm_pp_directives_key_array_111, 9},
{0, 0},
{0, 0},
{nasm_pp_directives_key_array_114, 8},
{nasm_pp_directives_key_array_115, 6},
{0, 0},
{nasm_pp_directives_key_array_117, 7},
{0, 0},
{0, 0},
{nasm_pp_directives_key_array_120, 6},
{0, 0},
{0, 0},
{0, 0},
{nasm_pp_directives_key_array_124, 10},
{0, 0},
{0, 0},
{0, 0},
{nasm_pp_directives_key_array_128, 5},
{0, 0},
{0, 0},
{0, 0},
{nasm_pp_directives_key_array_132, 7},
{nasm_pp_directives_key_array_133, 7},
{0, 0},
{0, 0},
{0, 0},
{nasm_pp_directives_key_array_137, 2},
{0, 0},
{nasm_pp_directives_key_array_139, 8},
{nasm_pp_directives_key_array_140, 7},
{nasm_pp_directives_key_array_141, 5},
{nasm_pp_directives_key_array_142, 7},
{nasm_pp_directives_key_array_143, 6},
{0, 0},
{0, 0},
{nasm_pp_directives_key_array_146, 9},
{nasm_pp_directives_key_array_147, 5},
{nasm_pp_directives_key_array_148, 4},
{0, 0},
{0, 0},
{nasm_pp_directives_key_array_151, 4},
{nasm_pp_directives_key_array_152, 7},
{nasm_pp_directives_key_array_153, 5},
{0, 0},
{nasm_pp_directives_key_array_155, 6},
{0, 0},
{nasm_pp_directives_key_array_157, 5},
{0, 0},
{0, 0},
{nasm_pp_directives_key_array_160, 8},
{nasm_pp_directives_key_array_161, 6},
{0, 0},
{nasm_pp_directives_key_array_163, 7},
{nasm_pp_directives_key_array_164, 5},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{nasm_pp_directives_key_array_171, 5},
{nasm_pp_directives_key_array_172, 8},
{0, 0},
{0, 0},
{nasm_pp_directives_key_array_175, 6},
{0, 0},
{0, 0},
{nasm_pp_directives_key_array_178, 6},
};
Lexeme_Table_Value nasm_pp_directives_value_array[179] = {
{5, TokenNasmKind_undef},
{5, TokenNasmKind_ifnidni},
{0, 0},
{0, 0},
{5, TokenNasmKind_elifid},
{5, TokenNasmKind_endcomment},
{0, 0},
{5, TokenNasmKind_ifnempty},
{5, TokenNasmKind_error},
{5, TokenNasmKind_unimacro},
{5, TokenNasmKind_elifnctx},
{0, 0},
{0, 0},
{5, TokenNasmKind_defstr},
{5, TokenNasmKind_ifmacro},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{5, TokenNasmKind_iassign},
{5, TokenNasmKind_elifnid},
{5, TokenNasmKind_ifenv},
{5, TokenNasmKind_ifdef},
{5, TokenNasmKind_xdefine},
{0, 0},
{0, 0},
{0, 0},
{5, TokenNasmKind_repl},
{5, TokenNasmKind_macro},
{0, 0},
{0, 0},
{5, TokenNasmKind_ifempty},
{5, TokenNasmKind_ixdefine},
{5, TokenNasmKind_endm},
{5, TokenNasmKind_ifid},
{0, 0},
{5, TokenNasmKind_elifntoken},
{5, TokenNasmKind_iftoken},
{0, 0},
{5, TokenNasmKind_ifnenv},
{5, TokenNasmKind_elifnempty},
{5, TokenNasmKind_elifstr},
{5, TokenNasmKind_ifnstr},
{5, TokenNasmKind_clear},
{0, 0},
{5, TokenNasmKind_endif},
{5, TokenNasmKind_elifnstr},
{5, TokenNasmKind_define},
{5, TokenNasmKind_ifidni},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{5, TokenNasmKind_rep},
{0, 0},
{5, TokenNasmKind_ifn},
{0, 0},
{0, 0},
{0, 0},
{5, TokenNasmKind_include},
{0, 0},
{5, TokenNasmKind_ifnctx},
{5, TokenNasmKind_ifndef},
{5, TokenNasmKind_imacro},
{0, 0},
{5, TokenNasmKind_else},
{5, TokenNasmKind_use},
{0, 0},
{5, TokenNasmKind_elifnnum},
{5, TokenNasmKind_pop},
{5, TokenNasmKind_elifidni},
{5, TokenNasmKind_ideftok},
{0, 0},
{0, 0},
{5, TokenNasmKind_elifempty},
{5, TokenNasmKind_exitrep},
{0, 0},
{5, TokenNasmKind_elifnenv},
{0, 0},
{5, TokenNasmKind_elifnidni},
{5, TokenNasmKind_arg},
{5, TokenNasmKind_elif},
{0, 0},
{0, 0},
{5, TokenNasmKind_deftok},
{5, TokenNasmKind_strlen},
{5, TokenNasmKind_elifctx},
{0, 0},
{5, TokenNasmKind_ifntoken},
{5, TokenNasmKind_pathsearch},
{0, 0},
{0, 0},
{5, TokenNasmKind_rmacro},
{5, TokenNasmKind_ifstr},
{0, 0},
{0, 0},
{0, 0},
{5, TokenNasmKind_idefine},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{5, TokenNasmKind_rotate},
{5, TokenNasmKind_stacksize},
{0, 0},
{5, TokenNasmKind_elifmacro},
{0, 0},
{5, TokenNasmKind_irmacro},
{5, TokenNasmKind_exitmacro},
{0, 0},
{0, 0},
{5, TokenNasmKind_ifnmacro},
{5, TokenNasmKind_ifnnum},
{0, 0},
{5, TokenNasmKind_elifdef},
{0, 0},
{0, 0},
{5, TokenNasmKind_substr},
{0, 0},
{0, 0},
{0, 0},
{5, TokenNasmKind_elifnmacro},
{0, 0},
{0, 0},
{0, 0},
{5, TokenNasmKind_ifctx},
{0, 0},
{0, 0},
{0, 0},
{5, TokenNasmKind_idefstr},
{5, TokenNasmKind_unmacro},
{0, 0},
{0, 0},
{0, 0},
{5, TokenNasmKind_if},
{0, 0},
{5, TokenNasmKind_elifndef},
{5, TokenNasmKind_elifenv},
{5, TokenNasmKind_ifidn},
{5, TokenNasmKind_elifnum},
{5, TokenNasmKind_endrep},
{0, 0},
{0, 0},
{5, TokenNasmKind_eliftoken},
{5, TokenNasmKind_elifn},
{5, TokenNasmKind_line},
{0, 0},
{0, 0},
{5, TokenNasmKind_push},
{5, TokenNasmKind_comment},
{5, TokenNasmKind_local},
{0, 0},
{5, TokenNasmKind_assign},
{0, 0},
{5, TokenNasmKind_ifnid},
{0, 0},
{0, 0},
{5, TokenNasmKind_endmacro},
{5, TokenNasmKind_strcat},
{0, 0},
{5, TokenNasmKind_elifidn},
{5, TokenNasmKind_fatal},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{5, TokenNasmKind_ifnum},
{5, TokenNasmKind_elifnidn},
{0, 0},
{0, 0},
{5, TokenNasmKind_depend},
{0, 0},
{0, 0},
{5, TokenNasmKind_ifnidn},
};
i32 nasm_pp_directives_slot_count = 179;
u64 nasm_pp_directives_seed = 0xa6fcd65e357775af;
struct Lex_State_Nasm{
u32 flags_ZF0;
u8 *base;
u8 *delim_first;
u8 *delim_one_past_last;
u8 *emit_ptr;
u8 *ptr;
u8 *opl_ptr;
};
internal void
lex_full_input_nasm_init(Lex_State_Nasm *state_ptr, String_Const_u8 input){
state_ptr->flags_ZF0 = 0;
state_ptr->base = input.str;
state_ptr->delim_first = input.str;
state_ptr->delim_one_past_last = input.str;
state_ptr->emit_ptr = input.str;
state_ptr->ptr = input.str;
state_ptr->opl_ptr = input.str + input.size;
}
internal b32
lex_full_input_nasm_breaks(Arena *arena, Token_List *list, Lex_State_Nasm *state_ptr, u64 max){
b32 result = false;
u64 emit_counter = 0;
Lex_State_Nasm state;
block_copy_struct(&state, state_ptr);
{
state_label_1: // root
if (state.ptr == state.opl_ptr){
if ((true)){
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
do{
token.sub_kind = TokenNasmKind_EOF;
token.kind = 0;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
}
state.flags_ZF0 = 0;
result = true;
goto end;
}
}
switch (*state.ptr){
case 0x00:case 0x01:case 0x02:case 0x03:case 0x04:case 0x05:case 0x06:
case 0x07:case 0x08:case 0x0e:case 0x0f:case 0x10:case 0x11:case 0x12:
case 0x13:case 0x14:case 0x15:case 0x16:case 0x17:case 0x18:case 0x19:
case 0x1a:case 0x1b:case 0x1c:case 0x1d:case 0x1e:case 0x1f:case 0x21:
case 0x23:case 0x24:case 0x26:case 0x2a:case 0x2c:case 0x2f:case 0x3c:
case 0x3d:case 0x3e:case 0x3f:case 0x40:case 0x5c:case 0x5e:case 0x60:
case 0x7b:case 0x7c:case 0x7d:case 0x7f:
{
state.ptr += 1;
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
do{
token.sub_kind = TokenNasmKind_LexError;
token.kind = 2;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_ZF0 = 0;
goto state_label_1; // root
}break;
case 0x09:case 0x0a:case 0x0b:case 0x0c:case 0x0d:case 0x20:
{
state.ptr += 1;
goto state_label_3; // whitespace
}break;
case 0x22:
{
state.ptr += 1;
goto state_label_16; // string
}break;
case 0x25:
{
state.ptr += 1;
state.delim_first = state.ptr;
goto state_label_18; // preprocessor_rest
}break;
case 0x27:
{
state.ptr += 1;
state.flags_ZF0 |= 0x8;
goto state_label_16; // string
}break;
case 0x28:
{
state.ptr += 1;
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
do{
token.sub_kind = TokenNasmKind_ParenOp;
token.kind = 7;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_ZF0 = 0;
goto state_label_1; // root
}break;
case 0x29:
{
state.ptr += 1;
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
do{
token.sub_kind = TokenNasmKind_ParenCl;
token.kind = 7;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_ZF0 = 0;
goto state_label_1; // root
}break;
case 0x2b:
{
state.ptr += 1;
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
do{
token.sub_kind = TokenNasmKind_Plus;
token.kind = 7;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_ZF0 = 0;
goto state_label_1; // root
}break;
case 0x2d:
{
state.ptr += 1;
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
do{
token.sub_kind = TokenNasmKind_Minus;
token.kind = 7;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_ZF0 = 0;
goto state_label_1; // root
}break;
case 0x2e:
{
state.ptr += 1;
goto state_label_4; // operator_or_fnumber_dot
}break;
case 0x30:
{
state.ptr += 1;
goto state_label_6; // znumber
}break;
case 0x31:case 0x32:case 0x33:case 0x34:case 0x35:case 0x36:case 0x37:
case 0x38:case 0x39:
{
state.ptr += 1;
goto state_label_5; // number
}break;
case 0x3a:
{
state.ptr += 1;
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
do{
token.sub_kind = TokenNasmKind_Colon;
token.kind = 7;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_ZF0 = 0;
goto state_label_1; // root
}break;
case 0x3b:
{
state.ptr += 1;
goto state_label_17; // comment_line
}break;
default:
{
state.ptr += 1;
goto state_label_2; // identifier
}break;
case 0x5b:
{
state.ptr += 1;
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
do{
token.sub_kind = TokenNasmKind_BrackOp;
token.kind = 7;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_ZF0 = 0;
goto state_label_1; // root
}break;
case 0x5d:
{
state.ptr += 1;
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
do{
token.sub_kind = TokenNasmKind_BrackCl;
token.kind = 7;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_ZF0 = 0;
goto state_label_1; // root
}break;
case 0x7e:
{
state.ptr += 1;
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
do{
token.sub_kind = TokenNasmKind_Tilde;
token.kind = 7;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_ZF0 = 0;
goto state_label_1; // root
}break;
}
}
{
state_label_2: // identifier
if (state.ptr == state.opl_ptr){
if ((true)){
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
do{
Lexeme_Table_Lookup lookup = lexeme_table_lookup(nasm_main_keys_hash_array, nasm_main_keys_key_array, nasm_main_keys_value_array, nasm_main_keys_slot_count, nasm_main_keys_seed, state.emit_ptr, token.size);
if (lookup.found_match){
token.kind = lookup.base_kind;
token.sub_kind = lookup.sub_kind;
break;
}
token.sub_kind = TokenNasmKind_Identifier;
token.kind = 6;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
}
state.flags_ZF0 = 0;
goto state_label_1; // root
}
}
switch (*state.ptr){
case 0x00:case 0x01:case 0x02:case 0x03:case 0x04:case 0x05:case 0x06:
case 0x07:case 0x08:case 0x09:case 0x0a:case 0x0b:case 0x0c:case 0x0d:
case 0x0e:case 0x0f:case 0x10:case 0x11:case 0x12:case 0x13:case 0x14:
case 0x15:case 0x16:case 0x17:case 0x18:case 0x19:case 0x1a:case 0x1b:
case 0x1c:case 0x1d:case 0x1e:case 0x1f:case 0x20:case 0x21:case 0x22:
case 0x23:case 0x24:case 0x25:case 0x26:case 0x27:case 0x28:case 0x29:
case 0x2a:case 0x2b:case 0x2c:case 0x2d:case 0x2e:case 0x2f:case 0x3a:
case 0x3b:case 0x3c:case 0x3d:case 0x3e:case 0x3f:case 0x40:case 0x5b:
case 0x5c:case 0x5d:case 0x5e:case 0x60:case 0x7b:case 0x7c:case 0x7d:
case 0x7e:case 0x7f:
{
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
do{
Lexeme_Table_Lookup lookup = lexeme_table_lookup(nasm_main_keys_hash_array, nasm_main_keys_key_array, nasm_main_keys_value_array, nasm_main_keys_slot_count, nasm_main_keys_seed, state.emit_ptr, token.size);
if (lookup.found_match){
token.kind = lookup.base_kind;
token.sub_kind = lookup.sub_kind;
break;
}
token.sub_kind = TokenNasmKind_Identifier;
token.kind = 6;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_ZF0 = 0;
goto state_label_1; // root
}break;
default:
{
state.ptr += 1;
goto state_label_2; // identifier
}break;
}
}
{
state_label_3: // whitespace
if (state.ptr == state.opl_ptr){
if ((true)){
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
do{
token.sub_kind = TokenNasmKind_Whitespace;
token.kind = 1;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
}
state.flags_ZF0 = 0;
goto state_label_1; // root
}
}
switch (*state.ptr){
default:
{
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
do{
token.sub_kind = TokenNasmKind_Whitespace;
token.kind = 1;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_ZF0 = 0;
goto state_label_1; // root
}break;
case 0x09:case 0x0a:case 0x0b:case 0x0c:case 0x0d:case 0x20:
{
state.ptr += 1;
goto state_label_3; // whitespace
}break;
}
}
{
state_label_4: // operator_or_fnumber_dot
if (state.ptr == state.opl_ptr){
if ((true)){
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
do{
token.sub_kind = TokenNasmKind_Dot;
token.kind = 7;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
}
state.flags_ZF0 = 0;
goto state_label_1; // root
}
}
switch (*state.ptr){
case 0x00:case 0x01:case 0x02:case 0x03:case 0x04:case 0x05:case 0x06:
case 0x07:case 0x08:case 0x09:case 0x0a:case 0x0b:case 0x0c:case 0x0d:
case 0x0e:case 0x0f:case 0x10:case 0x11:case 0x12:case 0x13:case 0x14:
case 0x15:case 0x16:case 0x17:case 0x18:case 0x19:case 0x1a:case 0x1b:
case 0x1c:case 0x1d:case 0x1e:case 0x1f:case 0x20:case 0x21:case 0x22:
case 0x23:case 0x24:case 0x25:case 0x26:case 0x27:case 0x28:case 0x29:
case 0x2a:case 0x2b:case 0x2c:case 0x2d:case 0x2e:case 0x2f:case 0x3a:
case 0x3b:case 0x3c:case 0x3d:case 0x3e:case 0x3f:case 0x40:case 0x5b:
case 0x5c:case 0x5d:case 0x5e:case 0x60:case 0x7b:case 0x7c:case 0x7d:
case 0x7e:case 0x7f:
{
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
do{
token.sub_kind = TokenNasmKind_Dot;
token.kind = 7;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_ZF0 = 0;
goto state_label_1; // root
}break;
case 0x30:case 0x31:case 0x32:case 0x33:case 0x34:case 0x35:case 0x36:
case 0x37:case 0x38:case 0x39:
{
state.ptr += 1;
goto state_label_7; // fnumber_decimal
}break;
default:
{
state.ptr += 1;
goto state_label_2; // identifier
}break;
}
}
{
state_label_5: // number
if (state.ptr == state.opl_ptr){
if ((true)){
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
do{
token.sub_kind = TokenNasmKind_LiteralInteger;
token.kind = 8;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
}
state.flags_ZF0 = 0;
goto state_label_1; // root
}
}
switch (*state.ptr){
default:
{
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
do{
token.sub_kind = TokenNasmKind_LiteralInteger;
token.kind = 8;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_ZF0 = 0;
goto state_label_1; // root
}break;
case 0x2e:
{
state.ptr += 1;
goto state_label_7; // fnumber_decimal
}break;
case 0x30:case 0x31:case 0x32:case 0x33:case 0x34:case 0x35:case 0x36:
case 0x37:case 0x38:case 0x39:case 0x5f:case 0x62:case 0x68:
{
state.ptr += 1;
goto state_label_5; // number
}break;
case 0x45:case 0x65:
{
state.ptr += 1;
goto state_label_8; // fnumber_exponent
}break;
}
}
{
state_label_6: // znumber
if (state.ptr == state.opl_ptr){
if ((true)){
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
do{
token.sub_kind = TokenNasmKind_LiteralInteger;
token.kind = 8;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
}
state.flags_ZF0 = 0;
goto state_label_1; // root
}
}
switch (*state.ptr){
default:
{
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
do{
token.sub_kind = TokenNasmKind_LiteralInteger;
token.kind = 8;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_ZF0 = 0;
goto state_label_1; // root
}break;
case 0x2e:
{
state.ptr += 1;
goto state_label_7; // fnumber_decimal
}break;
case 0x30:case 0x31:case 0x32:case 0x33:case 0x34:case 0x35:case 0x36:
case 0x37:case 0x38:case 0x39:case 0x5f:
{
state.ptr += 1;
goto state_label_5; // number
}break;
case 0x42:case 0x62:
{
state.ptr += 1;
state.flags_ZF0 |= 0x4;
goto state_label_12; // number_bin_first
}break;
case 0x45:case 0x65:
{
state.ptr += 1;
goto state_label_8; // fnumber_exponent
}break;
case 0x4f:case 0x6f:
{
state.ptr += 1;
state.flags_ZF0 |= 0x2;
goto state_label_14; // number_oct
}break;
case 0x58:case 0x78:
{
state.ptr += 1;
state.flags_ZF0 |= 0x1;
goto state_label_11; // number_hex_first
}break;
}
}
{
state_label_7: // fnumber_decimal
if (state.ptr == state.opl_ptr){
if ((true)){
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
do{
token.sub_kind = TokenNasmKind_LiteralFloat;
token.kind = 9;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
}
state.flags_ZF0 = 0;
goto state_label_1; // root
}
}
switch (*state.ptr){
default:
{
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
do{
token.sub_kind = TokenNasmKind_LiteralFloat;
token.kind = 9;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_ZF0 = 0;
goto state_label_1; // root
}break;
case 0x30:case 0x31:case 0x32:case 0x33:case 0x34:case 0x35:case 0x36:
case 0x37:case 0x38:case 0x39:
{
state.ptr += 1;
goto state_label_7; // fnumber_decimal
}break;
case 0x45:case 0x65:
{
state.ptr += 1;
goto state_label_8; // fnumber_exponent
}break;
}
}
{
state_label_8: // fnumber_exponent
if (state.ptr == state.opl_ptr){
if ((true)){
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
do{
token.sub_kind = TokenNasmKind_LiteralFloat;
token.kind = 9;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
}
state.flags_ZF0 = 0;
goto state_label_1; // root
}
}
switch (*state.ptr){
default:
{
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
do{
token.sub_kind = TokenNasmKind_LiteralFloat;
token.kind = 9;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_ZF0 = 0;
goto state_label_1; // root
}break;
case 0x2b:case 0x2d:
{
state.ptr += 1;
goto state_label_9; // fnumber_exponent_sign
}break;
case 0x30:case 0x31:case 0x32:case 0x33:case 0x34:case 0x35:case 0x36:
case 0x37:case 0x38:case 0x39:
{
state.ptr += 1;
goto state_label_10; // fnumber_exponent_digits
}break;
}
}
{
state_label_9: // fnumber_exponent_sign
if (state.ptr == state.opl_ptr){
if ((true)){
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
do{
token.sub_kind = TokenNasmKind_LiteralFloat;
token.kind = 9;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
}
state.flags_ZF0 = 0;
goto state_label_1; // root
}
}
switch (*state.ptr){
default:
{
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
do{
token.sub_kind = TokenNasmKind_LiteralFloat;
token.kind = 9;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_ZF0 = 0;
goto state_label_1; // root
}break;
case 0x30:case 0x31:case 0x32:case 0x33:case 0x34:case 0x35:case 0x36:
case 0x37:case 0x38:case 0x39:
{
state.ptr += 1;
goto state_label_10; // fnumber_exponent_digits
}break;
}
}
{
state_label_10: // fnumber_exponent_digits
if (state.ptr == state.opl_ptr){
if ((true)){
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
do{
token.sub_kind = TokenNasmKind_LiteralFloat;
token.kind = 9;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
}
state.flags_ZF0 = 0;
goto state_label_1; // root
}
}
switch (*state.ptr){
default:
{
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
do{
token.sub_kind = TokenNasmKind_LiteralFloat;
token.kind = 9;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_ZF0 = 0;
goto state_label_1; // root
}break;
case 0x30:case 0x31:case 0x32:case 0x33:case 0x34:case 0x35:case 0x36:
case 0x37:case 0x38:case 0x39:
{
state.ptr += 1;
goto state_label_10; // fnumber_exponent_digits
}break;
}
}
{
state_label_11: // number_hex_first
if (state.ptr == state.opl_ptr){
if ((true)){
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
do{
token.sub_kind = TokenNasmKind_LexError;
token.kind = 2;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
}
state.flags_ZF0 = 0;
goto state_label_1; // root
}
}
switch (*state.ptr){
default:
{
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
do{
token.sub_kind = TokenNasmKind_LexError;
token.kind = 2;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_ZF0 = 0;
goto state_label_1; // root
}break;
case 0x30:case 0x31:case 0x32:case 0x33:case 0x34:case 0x35:case 0x36:
case 0x37:case 0x38:case 0x39:case 0x41:case 0x42:case 0x43:case 0x44:
case 0x45:case 0x46:case 0x61:case 0x62:case 0x63:case 0x64:case 0x65:
case 0x66:
{
state.ptr += 1;
goto state_label_13; // number_hex
}break;
}
}
{
state_label_12: // number_bin_first
if (state.ptr == state.opl_ptr){
if ((true)){
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
do{
token.sub_kind = TokenNasmKind_LexError;
token.kind = 2;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
}
state.flags_ZF0 = 0;
goto state_label_1; // root
}
}
switch (*state.ptr){
default:
{
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
do{
token.sub_kind = TokenNasmKind_LexError;
token.kind = 2;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_ZF0 = 0;
goto state_label_1; // root
}break;
case 0x30:case 0x31:
{
state.ptr += 1;
goto state_label_15; // number_bin
}break;
case 0x5f:
{
state.ptr += 1;
state.flags_ZF0 |= 0x4;
goto state_label_12; // number_bin_first
}break;
}
}
{
state_label_13: // number_hex
if (state.ptr == state.opl_ptr){
if ((true)){
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
do{
token.sub_kind = TokenNasmKind_LiteralIntegerHex;
token.kind = 8;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
}
state.flags_ZF0 = 0;
goto state_label_1; // root
}
}
switch (*state.ptr){
default:
{
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
do{
token.sub_kind = TokenNasmKind_LiteralIntegerHex;
token.kind = 8;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_ZF0 = 0;
goto state_label_1; // root
}break;
case 0x30:case 0x31:case 0x32:case 0x33:case 0x34:case 0x35:case 0x36:
case 0x37:case 0x38:case 0x39:case 0x41:case 0x42:case 0x43:case 0x44:
case 0x45:case 0x46:case 0x61:case 0x62:case 0x63:case 0x64:case 0x65:
case 0x66:
{
state.ptr += 1;
goto state_label_13; // number_hex
}break;
}
}
{
state_label_14: // number_oct
if (state.ptr == state.opl_ptr){
if ((true)){
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
do{
token.sub_kind = TokenNasmKind_LiteralIntegerOct;
token.kind = 8;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
}
state.flags_ZF0 = 0;
goto state_label_1; // root
}
}
switch (*state.ptr){
default:
{
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
do{
token.sub_kind = TokenNasmKind_LiteralIntegerOct;
token.kind = 8;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_ZF0 = 0;
goto state_label_1; // root
}break;
case 0x30:case 0x31:case 0x32:case 0x33:case 0x34:case 0x35:case 0x36:
case 0x37:
{
state.ptr += 1;
state.flags_ZF0 |= 0x2;
goto state_label_14; // number_oct
}break;
}
}
{
state_label_15: // number_bin
if (state.ptr == state.opl_ptr){
if ((true)){
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
do{
token.sub_kind = TokenNasmKind_LiteralIntegerBin;
token.kind = 8;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
}
state.flags_ZF0 = 0;
goto state_label_1; // root
}
}
switch (*state.ptr){
default:
{
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
do{
token.sub_kind = TokenNasmKind_LiteralIntegerBin;
token.kind = 8;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_ZF0 = 0;
goto state_label_1; // root
}break;
case 0x30:case 0x31:case 0x5f:
{
state.ptr += 1;
goto state_label_15; // number_bin
}break;
}
}
{
state_label_16: // string
if (state.ptr == state.opl_ptr){
if ((true)){
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
do{
token.sub_kind = TokenNasmKind_LexError;
token.kind = 2;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
}
state.flags_ZF0 = 0;
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
do{
token.sub_kind = TokenNasmKind_EOF;
token.kind = 0;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
}
state.flags_ZF0 = 0;
result = true;
goto end;
}
}
switch (*state.ptr){
default:
{
state.ptr += 1;
goto state_label_16; // string
}break;
case 0x22:
{
if ((!HasFlag(state.flags_ZF0, 0x8))){
state.ptr += 1;
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
do{
token.sub_kind = TokenNasmKind_LiteralString;
token.kind = 10;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_ZF0 = 0;
goto state_label_1; // root
}
state.ptr += 1;
goto state_label_16; // string
}break;
case 0x27:
{
if ((HasFlag(state.flags_ZF0, 0x8))){
state.ptr += 1;
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
do{
token.sub_kind = TokenNasmKind_LiteralCharacter;
token.kind = 10;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_ZF0 = 0;
goto state_label_1; // root
}
state.ptr += 1;
goto state_label_16; // string
}break;
}
}
{
state_label_17: // comment_line
if (state.ptr == state.opl_ptr){
if ((true)){
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
do{
token.sub_kind = TokenNasmKind_LineComment;
token.kind = 3;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
}
state.flags_ZF0 = 0;
goto state_label_1; // root
}
}
switch (*state.ptr){
default:
{
state.ptr += 1;
goto state_label_17; // comment_line
}break;
case 0x0a:
{
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
do{
token.sub_kind = TokenNasmKind_LineComment;
token.kind = 3;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_ZF0 = 0;
goto state_label_1; // root
}break;
}
}
{
state_label_18: // preprocessor_rest
if (state.ptr == state.opl_ptr){
if ((true)){
state.delim_one_past_last = state.ptr;
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
do{
Lexeme_Table_Lookup lookup = lexeme_table_lookup(nasm_pp_directives_hash_array, nasm_pp_directives_key_array, nasm_pp_directives_value_array, nasm_pp_directives_slot_count, nasm_pp_directives_seed, state.delim_first, (state.delim_one_past_last - state.delim_first));
if (lookup.found_match){
token.kind = lookup.base_kind;
token.sub_kind = lookup.sub_kind;
break;
}
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
}
state.flags_ZF0 = 0;
goto state_label_1; // root
}
}
switch (*state.ptr){
default:
{
state.delim_one_past_last = state.ptr;
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
do{
Lexeme_Table_Lookup lookup = lexeme_table_lookup(nasm_pp_directives_hash_array, nasm_pp_directives_key_array, nasm_pp_directives_value_array, nasm_pp_directives_slot_count, nasm_pp_directives_seed, state.delim_first, (state.delim_one_past_last - state.delim_first));
if (lookup.found_match){
token.kind = lookup.base_kind;
token.sub_kind = lookup.sub_kind;
break;
}
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_ZF0 = 0;
goto state_label_1; // root
}break;
case 0x30:case 0x31:case 0x32:case 0x33:case 0x34:case 0x35:case 0x36:
case 0x37:case 0x38:case 0x39:case 0x41:case 0x42:case 0x43:case 0x44:
case 0x45:case 0x46:case 0x47:case 0x48:case 0x49:case 0x4a:case 0x4b:
case 0x4c:case 0x4d:case 0x4e:case 0x4f:case 0x50:case 0x51:case 0x52:
case 0x53:case 0x54:case 0x55:case 0x56:case 0x57:case 0x58:case 0x59:
case 0x5a:case 0x61:case 0x62:case 0x63:case 0x64:case 0x65:case 0x66:
case 0x67:case 0x68:case 0x69:case 0x6a:case 0x6b:case 0x6c:case 0x6d:
case 0x6e:case 0x6f:case 0x70:case 0x71:case 0x72:case 0x73:case 0x74:
case 0x75:case 0x76:case 0x77:case 0x78:case 0x79:case 0x7a:
{
state.ptr += 1;
goto state_label_18; // preprocessor_rest
}break;
}
}
end:;
block_copy_struct(state_ptr, &state);
return(result);
}
internal Token_List
lex_full_input_nasm(Arena *arena, String_Const_u8 input){
Lex_State_Nasm state = {};
lex_full_input_nasm_init(&state, input);
Token_List list = {};
lex_full_input_nasm_breaks(arena, &list, &state, max_u64);
return(list);
}
