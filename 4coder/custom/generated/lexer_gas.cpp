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
u64 gas_main_keys_hash_array[219] = {
0x9c378bdf3da7c795,0x0000000000000000,0x0000000000000000,0xf513d9c012259e05,
0x8e905d008d3d6089,0xf513d9c012d2943d,0x47e64cab85832c39,0x47e64cab62a852ab,
0x0000000000000000,0x0000000000000000,0xf513d9c012259e0d,0x0000000000000000,
0x47e64cab79a93159,0x8e905d06d71c8a4d,0x8e905d063cc9b263,0x0000000000000000,
0xf513d9c012fda06d,0xf513d9c0121b60eb,0x0000000000000000,0x47e64cab8a7cffd3,
0x0000000000000000,0xf513d9c01218e477,0x0000000000000000,0x0000000000000000,
0x0000000000000000,0x8e905d1b942d5b83,0x9c37869bb31786f1,0x0000000000000000,
0x0000000000000000,0x8e905d0582cf2c03,0x0000000000000000,0x0000000000000000,
0x0000000000000000,0x0000000000000000,0xf513d9c012f9e415,0x0000000000000000,
0xcc6d971419003b33,0x9c378678e6d32929,0x0000000000000000,0x47e64cab7dde541d,
0x98c9a0dd1d863c6b,0xf513d9c012d78157,0xf513d9c0121e98d5,0xf513d9c012d6fb09,
0x0000000000000000,0x0000000000000000,0x8e905d1b98eebd6d,0xf513d9c0121e98db,
0x98c9a0dd1d868971,0xf513d9c0121e98db,0x0000000000000000,0x9c37869e8b698f4d,
0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000,
0x0000000000000000,0x47e64cab7dff2409,0x0000000000000000,0x0000000000000000,
0x8e905d1bf148b215,0x0000000000000000,0x9c378b1c36a9784d,0x8eb63faaec5f2929,
0x0000000000000000,0x47e64cab8a2e5df9,0x9c37867d23fd9719,0x0000000000000000,
0x98c9a0dd1d873809,0x0000000000000000,0x0000000000000000,0x98c9a0dd1d87380b,
0x98c9a0dd1d870d47,0x98c9a0dd1d870d47,0x0000000000000000,0x0000000000000000,
0x6c9535bd92492929,0x0000000000000000,0x0000000000000000,0x0000000000000000,
0x0000000000000000,0x98c9a0dd1d854d0b,0xf513d9c012c5bc1d,0x8e905d1b942e6aeb,
0x0000000000000000,0x0000000000000000,0x0000000000000000,0x98c9a0dd1d8738f7,
0x47e64cab85a86309,0x0000000000000000,0x47e64cab88b19a89,0xa41813dfc62a4ffb,
0x9c378b2f236436eb,0x0000000000000000,0x0000000000000000,0x47e64cab79ac0d19,
0x0000000000000000,0x8e905d0011179c99,0x98c9a0dd1d86855b,0x0000000000000000,
0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000,
0x0000000000000000,0xf513d9c0121e81fb,0x47e64cab785fce29,0x0000000000000000,
0x0000000000000000,0x0000000000000000,0xa4182b63f0627203,0x0000000000000000,
0x0000000000000000,0x0000000000000000,0x47e64cab7f8fa0c3,0xf513d9c012ff44d9,
0x47e64cab7ec239ad,0x0000000000000000,0x8066196394c26a43,0x0000000000000000,
0x47e64cab7c9e29f9,0xf513d9c0121e9849,0x0000000000000000,0x47e64cab7dcf03d5,
0x0000000000000000,0x98c9a0dd1d85ddcb,0x0000000000000000,0x0000000000000000,
0x0000000000000000,0x0000000000000000,0xcc6d971419003b91,0xf513d9c012e04efd,
0xf513d9c012101797,0x0000000000000000,0x0000000000000000,0x47e64cab7ec239bf,
0xf513d9c0121e9859,0x0000000000000000,0x0000000000000000,0x0000000000000000,
0x0000000000000000,0x8b34bd7576764929,0x98c9a0dd1d85ac3d,0x98c9a0dd1d858ae1,
0xf513d9c012b41259,0x0000000000000000,0xf513d9c012012bfb,0x8e905d07577ad619,
0x0000000000000000,0x0000000000000000,0xa41814158480a22b,0x0000000000000000,
0x0000000000000000,0xa418f0ad9d4df6c5,0xf513d9c012ba700d,0x0000000000000000,
0x0000000000000000,0x0000000000000000,0x8e905d134bfd30e9,0x98c9a0dd1d85d8cb,
0x0000000000000000,0x0000000000000000,0x0000000000000000,0x47e64cab8a08d771,
0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000,
0x0000000000000000,0x47e64cab7c9fe471,0x47e64cab86f39403,0x0000000000000000,
0x47e64cab78d1a4d1,0xf513d9c0121beb43,0x0000000000000000,0xf513d9c0121bea69,
0xad393a352046d623,0x0000000000000000,0x0000000000000000,0xf513d9c0122723f3,
0x0000000000000000,0x98c9a0dd1d870295,0x0000000000000000,0x98c9a0dd1d86c349,
0xf513d9c0121e816f,0x98c9a0dd1d870299,0x8e905d0547cd7443,0x0000000000000000,
0x0000000000000000,0x47e64cab7c982d3d,0xf513d9c012c359bb,0x9c378b3a22c220d9,
0x8e905d0784143cb1,0xa418281f8977ecf1,0x0000000000000000,0xf513d9c012e39e29,
0xf513d9c012d6b57d,0x0000000000000000,0x47e64cab7c9fd005,0x8e905d008c7a502b,
0x0000000000000000,0xbf0665d494f2d203,0x47e64cab7dc382c3,0xaf7b3a34caac6119,
0x8e905d07dff320d9,0x0000000000000000,0x47e64cab78d18471,0x9c378bddc1bd1977,
0x0000000000000000,0x0000000000000000,0x0000000000000000,0xf513d9c0121e818b,
0x0000000000000000,0xf513d9c012fb12c3,0x0000000000000000,0xfa6a9ac1ab083e43,
0x0000000000000000,0x0000000000000000,0x0000000000000000,
};
u8 gas_main_keys_key_array_0[] = {0x69,0x6e,0x63,0x6c,0x75,0x64,0x65,};
u8 gas_main_keys_key_array_3[] = {0x66,0x69,0x6c,0x65,};
u8 gas_main_keys_key_array_4[] = {0x68,0x69,0x64,0x64,0x65,0x6e,};
u8 gas_main_keys_key_array_5[] = {0x72,0x65,0x70,0x74,};
u8 gas_main_keys_key_array_6[] = {0x70,0x72,0x69,0x6e,0x74,};
u8 gas_main_keys_key_array_7[] = {0x66,0x6c,0x6f,0x61,0x74,};
u8 gas_main_keys_key_array_10[] = {0x66,0x69,0x6c,0x6c,};
u8 gas_main_keys_key_array_12[] = {0x61,0x6c,0x69,0x67,0x6e,};
u8 gas_main_keys_key_array_13[] = {0x6c,0x66,0x6c,0x61,0x67,0x73,};
u8 gas_main_keys_key_array_14[] = {0x65,0x78,0x74,0x65,0x72,0x6e,};
u8 gas_main_keys_key_array_16[] = {0x64,0x65,0x73,0x63,};
u8 gas_main_keys_key_array_17[] = {0x6c,0x6f,0x6e,0x67,};
u8 gas_main_keys_key_array_19[] = {0x73,0x70,0x61,0x63,0x65,};
u8 gas_main_keys_key_array_21[] = {0x66,0x75,0x6e,0x63,};
u8 gas_main_keys_key_array_25[] = {0x73,0x74,0x72,0x75,0x63,0x74,};
u8 gas_main_keys_key_array_26[] = {0x77,0x65,0x61,0x6b,0x72,0x65,0x66,};
u8 gas_main_keys_key_array_29[] = {0x6e,0x6f,0x6c,0x69,0x73,0x74,};
u8 gas_main_keys_key_array_34[] = {0x62,0x79,0x74,0x65,};
u8 gas_main_keys_key_array_36[] = {0x6c,0x6e,};
u8 gas_main_keys_key_array_37[] = {0x73,0x65,0x63,0x74,0x69,0x6f,0x6e,};
u8 gas_main_keys_key_array_39[] = {0x65,0x78,0x69,0x74,0x6d,};
u8 gas_main_keys_key_array_40[] = {0x76,0x61,0x6c,};
u8 gas_main_keys_key_array_41[] = {0x73,0x6b,0x69,0x70,};
u8 gas_main_keys_key_array_42[] = {0x69,0x66,0x6e,0x65,};
u8 gas_main_keys_key_array_43[] = {0x73,0x69,0x7a,0x65,};
u8 gas_main_keys_key_array_46[] = {0x73,0x79,0x6d,0x76,0x65,0x72,};
u8 gas_main_keys_key_array_47[] = {0x69,0x66,0x6e,0x62,};
u8 gas_main_keys_key_array_48[] = {0x64,0x65,0x66,};
u8 gas_main_keys_key_array_49[] = {0x69,0x66,0x6e,0x63,};
u8 gas_main_keys_key_array_51[] = {0x73,0x6c,0x65,0x62,0x31,0x32,0x38,};
u8 gas_main_keys_key_array_57[] = {0x65,0x71,0x75,0x69,0x76,};
u8 gas_main_keys_key_array_60[] = {0x73,0x69,0x6e,0x67,0x6c,0x65,};
u8 gas_main_keys_key_array_62[] = {0x75,0x6c,0x65,0x62,0x31,0x32,0x38,};
u8 gas_main_keys_key_array_63[] = {0x70,0x6f,0x70,0x73,0x65,0x63,0x74,0x69,0x6f,0x6e,};
u8 gas_main_keys_key_array_65[] = {0x73,0x68,0x6f,0x72,0x74,};
u8 gas_main_keys_key_array_66[] = {0x76,0x65,0x72,0x73,0x69,0x6f,0x6e,};
u8 gas_main_keys_key_array_68[] = {0x65,0x71,0x76,};
u8 gas_main_keys_key_array_71[] = {0x65,0x71,0x75,};
u8 gas_main_keys_key_array_72[] = {0x69,0x66,0x62,};
u8 gas_main_keys_key_array_73[] = {0x69,0x66,0x63,};
u8 gas_main_keys_key_array_76[] = {0x70,0x75,0x73,0x68,0x73,0x65,0x63,0x74,0x69,0x6f,0x6e,};
u8 gas_main_keys_key_array_81[] = {0x6f,0x72,0x67,};
u8 gas_main_keys_key_array_82[] = {0x74,0x65,0x78,0x74,};
u8 gas_main_keys_key_array_83[] = {0x73,0x74,0x72,0x69,0x6e,0x67,};
u8 gas_main_keys_key_array_87[] = {0x65,0x72,0x72,};
u8 gas_main_keys_key_array_88[] = {0x70,0x73,0x69,0x7a,0x65,};
u8 gas_main_keys_key_array_90[] = {0x74,0x69,0x74,0x6c,0x65,};
u8 gas_main_keys_key_array_91[] = {0x6c,0x69,0x6e,0x6b,0x6f,0x6e,0x63,0x65,};
u8 gas_main_keys_key_array_92[] = {0x77,0x61,0x72,0x6e,0x69,0x6e,0x67,};
u8 gas_main_keys_key_array_95[] = {0x61,0x62,0x6f,0x72,0x74,};
u8 gas_main_keys_key_array_97[] = {0x65,0x6c,0x73,0x65,0x69,0x66,};
u8 gas_main_keys_key_array_98[] = {0x64,0x69,0x6d,};
u8 gas_main_keys_key_array_105[] = {0x69,0x66,0x67,0x65,};
u8 gas_main_keys_key_array_106[] = {0x68,0x77,0x6f,0x72,0x64,};
u8 gas_main_keys_key_array_110[] = {0x61,0x6c,0x74,0x6d,0x61,0x63,0x72,0x6f,};
u8 gas_main_keys_key_array_114[] = {0x6c,0x63,0x6f,0x6d,0x6d,};
u8 gas_main_keys_key_array_115[] = {0x64,0x61,0x74,0x61,};
u8 gas_main_keys_key_array_116[] = {0x61,0x73,0x63,0x69,0x7a,};
u8 gas_main_keys_key_array_118[] = {0x64,0x65,0x70,0x72,0x65,0x63,0x61,0x74,0x65,0x64,};
u8 gas_main_keys_key_array_120[] = {0x69,0x64,0x65,0x6e,0x74,};
u8 gas_main_keys_key_array_121[] = {0x69,0x66,0x6c,0x65,};
u8 gas_main_keys_key_array_123[] = {0x65,0x72,0x72,0x6f,0x72,};
u8 gas_main_keys_key_array_125[] = {0x73,0x63,0x6c,};
u8 gas_main_keys_key_array_130[] = {0x69,0x66,};
u8 gas_main_keys_key_array_131[] = {0x77,0x65,0x61,0x6b,};
u8 gas_main_keys_key_array_132[] = {0x69,0x72,0x70,0x63,};
u8 gas_main_keys_key_array_135[] = {0x61,0x73,0x63,0x69,0x69,};
u8 gas_main_keys_key_array_136[] = {0x69,0x66,0x6c,0x74,};
u8 gas_main_keys_key_array_141[] = {0x73,0x75,0x62,0x73,0x65,0x63,0x74,0x69,0x6f,0x6e,};
u8 gas_main_keys_key_array_142[] = {0x6d,0x72,0x69,};
u8 gas_main_keys_key_array_143[] = {0x74,0x61,0x67,};
u8 gas_main_keys_key_array_144[] = {0x6f,0x63,0x74,0x61,};
u8 gas_main_keys_key_array_146[] = {0x65,0x6c,0x73,0x65,};
u8 gas_main_keys_key_array_147[] = {0x69,0x6e,0x63,0x62,0x69,0x6e,};
u8 gas_main_keys_key_array_150[] = {0x69,0x6e,0x74,0x65,0x72,0x6e,0x61,0x6c,};
u8 gas_main_keys_key_array_153[] = {0x70,0x72,0x65,0x76,0x69,0x6f,0x75,0x73,};
u8 gas_main_keys_key_array_154[] = {0x74,0x79,0x70,0x65,};
u8 gas_main_keys_key_array_158[] = {0x64,0x6f,0x75,0x62,0x6c,0x65,};
u8 gas_main_keys_key_array_159[] = {0x73,0x65,0x74,};
u8 gas_main_keys_key_array_163[] = {0x73,0x62,0x74,0x74,0x6c,};
u8 gas_main_keys_key_array_169[] = {0x69,0x66,0x64,0x65,0x66,};
u8 gas_main_keys_key_array_170[] = {0x6d,0x61,0x63,0x72,0x6f,};
u8 gas_main_keys_key_array_172[] = {0x65,0x6e,0x64,0x69,0x66,};
u8 gas_main_keys_key_array_173[] = {0x6c,0x69,0x73,0x74,};
u8 gas_main_keys_key_array_175[] = {0x6c,0x69,0x6e,0x65,};
u8 gas_main_keys_key_array_176[] = {0x70,0x72,0x6f,0x74,0x65,0x63,0x74,0x65,0x64,};
u8 gas_main_keys_key_array_179[] = {0x66,0x61,0x69,0x6c,};
u8 gas_main_keys_key_array_181[] = {0x69,0x72,0x70,};
u8 gas_main_keys_key_array_183[] = {0x65,0x6e,0x64,};
u8 gas_main_keys_key_array_184[] = {0x69,0x66,0x65,0x71,};
u8 gas_main_keys_key_array_185[] = {0x69,0x6e,0x74,};
u8 gas_main_keys_key_array_186[] = {0x70,0x75,0x72,0x67,0x65,0x6d,};
u8 gas_main_keys_key_array_189[] = {0x69,0x66,0x6e,0x65,0x73,};
u8 gas_main_keys_key_array_190[] = {0x71,0x75,0x61,0x64,};
u8 gas_main_keys_key_array_191[] = {0x70,0x32,0x61,0x6c,0x69,0x67,0x6e,};
u8 gas_main_keys_key_array_192[] = {0x69,0x66,0x6e,0x64,0x65,0x66,};
u8 gas_main_keys_key_array_193[] = {0x69,0x66,0x6e,0x6f,0x74,0x64,0x65,0x66,};
u8 gas_main_keys_key_array_195[] = {0x77,0x6f,0x72,0x64,};
u8 gas_main_keys_key_array_196[] = {0x73,0x74,0x61,0x62,};
u8 gas_main_keys_key_array_198[] = {0x69,0x66,0x65,0x71,0x73,};
u8 gas_main_keys_key_array_199[] = {0x67,0x6c,0x6f,0x62,0x61,0x6c,};
u8 gas_main_keys_key_array_201[] = {0x6e,0x6f,0x61,0x6c,0x74,0x6d,0x61,0x63,0x72,0x6f,};
u8 gas_main_keys_key_array_202[] = {0x65,0x6a,0x65,0x63,0x74,};
u8 gas_main_keys_key_array_203[] = {0x76,0x74,0x61,0x62,0x6c,0x65,0x65,0x6e,0x74,0x72,0x79,};
u8 gas_main_keys_key_array_204[] = {0x62,0x61,0x6c,0x69,0x67,0x6e,};
u8 gas_main_keys_key_array_206[] = {0x65,0x6e,0x64,0x65,0x66,};
u8 gas_main_keys_key_array_207[] = {0x65,0x6e,0x64,0x66,0x75,0x6e,0x63,};
u8 gas_main_keys_key_array_211[] = {0x69,0x66,0x67,0x74,};
u8 gas_main_keys_key_array_213[] = {0x63,0x6f,0x6d,0x6d,};
u8 gas_main_keys_key_array_215[] = {0x76,0x74,0x61,0x62,0x6c,0x65,0x69,0x6e,0x68,0x65,0x72,0x69,0x74,};
String_Const_u8 gas_main_keys_key_array[219] = {
{gas_main_keys_key_array_0, 7},
{0, 0},
{0, 0},
{gas_main_keys_key_array_3, 4},
{gas_main_keys_key_array_4, 6},
{gas_main_keys_key_array_5, 4},
{gas_main_keys_key_array_6, 5},
{gas_main_keys_key_array_7, 5},
{0, 0},
{0, 0},
{gas_main_keys_key_array_10, 4},
{0, 0},
{gas_main_keys_key_array_12, 5},
{gas_main_keys_key_array_13, 6},
{gas_main_keys_key_array_14, 6},
{0, 0},
{gas_main_keys_key_array_16, 4},
{gas_main_keys_key_array_17, 4},
{0, 0},
{gas_main_keys_key_array_19, 5},
{0, 0},
{gas_main_keys_key_array_21, 4},
{0, 0},
{0, 0},
{0, 0},
{gas_main_keys_key_array_25, 6},
{gas_main_keys_key_array_26, 7},
{0, 0},
{0, 0},
{gas_main_keys_key_array_29, 6},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{gas_main_keys_key_array_34, 4},
{0, 0},
{gas_main_keys_key_array_36, 2},
{gas_main_keys_key_array_37, 7},
{0, 0},
{gas_main_keys_key_array_39, 5},
{gas_main_keys_key_array_40, 3},
{gas_main_keys_key_array_41, 4},
{gas_main_keys_key_array_42, 4},
{gas_main_keys_key_array_43, 4},
{0, 0},
{0, 0},
{gas_main_keys_key_array_46, 6},
{gas_main_keys_key_array_47, 4},
{gas_main_keys_key_array_48, 3},
{gas_main_keys_key_array_49, 4},
{0, 0},
{gas_main_keys_key_array_51, 7},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{gas_main_keys_key_array_57, 5},
{0, 0},
{0, 0},
{gas_main_keys_key_array_60, 6},
{0, 0},
{gas_main_keys_key_array_62, 7},
{gas_main_keys_key_array_63, 10},
{0, 0},
{gas_main_keys_key_array_65, 5},
{gas_main_keys_key_array_66, 7},
{0, 0},
{gas_main_keys_key_array_68, 3},
{0, 0},
{0, 0},
{gas_main_keys_key_array_71, 3},
{gas_main_keys_key_array_72, 3},
{gas_main_keys_key_array_73, 3},
{0, 0},
{0, 0},
{gas_main_keys_key_array_76, 11},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{gas_main_keys_key_array_81, 3},
{gas_main_keys_key_array_82, 4},
{gas_main_keys_key_array_83, 6},
{0, 0},
{0, 0},
{0, 0},
{gas_main_keys_key_array_87, 3},
{gas_main_keys_key_array_88, 5},
{0, 0},
{gas_main_keys_key_array_90, 5},
{gas_main_keys_key_array_91, 8},
{gas_main_keys_key_array_92, 7},
{0, 0},
{0, 0},
{gas_main_keys_key_array_95, 5},
{0, 0},
{gas_main_keys_key_array_97, 6},
{gas_main_keys_key_array_98, 3},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{gas_main_keys_key_array_105, 4},
{gas_main_keys_key_array_106, 5},
{0, 0},
{0, 0},
{0, 0},
{gas_main_keys_key_array_110, 8},
{0, 0},
{0, 0},
{0, 0},
{gas_main_keys_key_array_114, 5},
{gas_main_keys_key_array_115, 4},
{gas_main_keys_key_array_116, 5},
{0, 0},
{gas_main_keys_key_array_118, 10},
{0, 0},
{gas_main_keys_key_array_120, 5},
{gas_main_keys_key_array_121, 4},
{0, 0},
{gas_main_keys_key_array_123, 5},
{0, 0},
{gas_main_keys_key_array_125, 3},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{gas_main_keys_key_array_130, 2},
{gas_main_keys_key_array_131, 4},
{gas_main_keys_key_array_132, 4},
{0, 0},
{0, 0},
{gas_main_keys_key_array_135, 5},
{gas_main_keys_key_array_136, 4},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{gas_main_keys_key_array_141, 10},
{gas_main_keys_key_array_142, 3},
{gas_main_keys_key_array_143, 3},
{gas_main_keys_key_array_144, 4},
{0, 0},
{gas_main_keys_key_array_146, 4},
{gas_main_keys_key_array_147, 6},
{0, 0},
{0, 0},
{gas_main_keys_key_array_150, 8},
{0, 0},
{0, 0},
{gas_main_keys_key_array_153, 8},
{gas_main_keys_key_array_154, 4},
{0, 0},
{0, 0},
{0, 0},
{gas_main_keys_key_array_158, 6},
{gas_main_keys_key_array_159, 3},
{0, 0},
{0, 0},
{0, 0},
{gas_main_keys_key_array_163, 5},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{gas_main_keys_key_array_169, 5},
{gas_main_keys_key_array_170, 5},
{0, 0},
{gas_main_keys_key_array_172, 5},
{gas_main_keys_key_array_173, 4},
{0, 0},
{gas_main_keys_key_array_175, 4},
{gas_main_keys_key_array_176, 9},
{0, 0},
{0, 0},
{gas_main_keys_key_array_179, 4},
{0, 0},
{gas_main_keys_key_array_181, 3},
{0, 0},
{gas_main_keys_key_array_183, 3},
{gas_main_keys_key_array_184, 4},
{gas_main_keys_key_array_185, 3},
{gas_main_keys_key_array_186, 6},
{0, 0},
{0, 0},
{gas_main_keys_key_array_189, 5},
{gas_main_keys_key_array_190, 4},
{gas_main_keys_key_array_191, 7},
{gas_main_keys_key_array_192, 6},
{gas_main_keys_key_array_193, 8},
{0, 0},
{gas_main_keys_key_array_195, 4},
{gas_main_keys_key_array_196, 4},
{0, 0},
{gas_main_keys_key_array_198, 5},
{gas_main_keys_key_array_199, 6},
{0, 0},
{gas_main_keys_key_array_201, 10},
{gas_main_keys_key_array_202, 5},
{gas_main_keys_key_array_203, 11},
{gas_main_keys_key_array_204, 6},
{0, 0},
{gas_main_keys_key_array_206, 5},
{gas_main_keys_key_array_207, 7},
{0, 0},
{0, 0},
{0, 0},
{gas_main_keys_key_array_211, 4},
{0, 0},
{gas_main_keys_key_array_213, 4},
{0, 0},
{gas_main_keys_key_array_215, 13},
{0, 0},
{0, 0},
{0, 0},
};
Lexeme_Table_Value gas_main_keys_value_array[219] = {
{4, TokenGasKind_Include},
{0, 0},
{0, 0},
{4, TokenGasKind_File},
{4, TokenGasKind_Hidden},
{4, TokenGasKind_Rept},
{4, TokenGasKind_Print},
{4, TokenGasKind_Float},
{0, 0},
{0, 0},
{4, TokenGasKind_Fill},
{0, 0},
{4, TokenGasKind_Align},
{4, TokenGasKind_Lflags},
{4, TokenGasKind_Extern},
{0, 0},
{4, TokenGasKind_Desc},
{4, TokenGasKind_Long},
{0, 0},
{4, TokenGasKind_Space},
{0, 0},
{4, TokenGasKind_Func},
{0, 0},
{0, 0},
{0, 0},
{4, TokenGasKind_Struct},
{4, TokenGasKind_Weakref},
{0, 0},
{0, 0},
{4, TokenGasKind_Nolist},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{4, TokenGasKind_Byte},
{0, 0},
{4, TokenGasKind_Ln},
{4, TokenGasKind_Section},
{0, 0},
{4, TokenGasKind_Exitm},
{4, TokenGasKind_Val},
{4, TokenGasKind_Skip},
{4, TokenGasKind_ifne},
{4, TokenGasKind_Size},
{0, 0},
{0, 0},
{4, TokenGasKind_Symver},
{4, TokenGasKind_ifnb},
{4, TokenGasKind_Def},
{4, TokenGasKind_ifnc},
{0, 0},
{4, TokenGasKind_Sleb128},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{4, TokenGasKind_Equiv},
{0, 0},
{0, 0},
{4, TokenGasKind_Single},
{0, 0},
{4, TokenGasKind_Uleb128},
{4, TokenGasKind_PopSection},
{0, 0},
{4, TokenGasKind_Short},
{4, TokenGasKind_Version},
{0, 0},
{4, TokenGasKind_Eqv},
{0, 0},
{0, 0},
{4, TokenGasKind_Equ},
{4, TokenGasKind_ifb},
{4, TokenGasKind_ifc},
{0, 0},
{0, 0},
{4, TokenGasKind_PushSection},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{4, TokenGasKind_Org},
{4, TokenGasKind_Text},
{4, TokenGasKind_String},
{0, 0},
{0, 0},
{0, 0},
{4, TokenGasKind_Err},
{4, TokenGasKind_Psize},
{0, 0},
{4, TokenGasKind_Title},
{4, TokenGasKind_Linkonce},
{4, TokenGasKind_Warning},
{0, 0},
{0, 0},
{4, TokenGasKind_Abort},
{0, 0},
{4, TokenGasKind_Elseif},
{4, TokenGasKind_Dim},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{4, TokenGasKind_ifge},
{4, TokenGasKind_hword},
{0, 0},
{0, 0},
{0, 0},
{4, TokenGasKind_Altmacro},
{0, 0},
{0, 0},
{0, 0},
{4, TokenGasKind_Lcomm},
{4, TokenGasKind_Data},
{4, TokenGasKind_Asciz},
{0, 0},
{4, TokenGasKind_Deprecated},
{0, 0},
{4, TokenGasKind_Ident},
{4, TokenGasKind_ifle},
{0, 0},
{4, TokenGasKind_Error},
{0, 0},
{4, TokenGasKind_Scl},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{4, TokenGasKind_If},
{4, TokenGasKind_Weak},
{4, TokenGasKind_Irpc},
{0, 0},
{0, 0},
{4, TokenGasKind_Ascii},
{4, TokenGasKind_iflt},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{4, TokenGasKind_SubSection},
{4, TokenGasKind_MRI},
{4, TokenGasKind_Tag},
{4, TokenGasKind_Octa},
{0, 0},
{4, TokenGasKind_Else},
{4, TokenGasKind_Incbin},
{0, 0},
{0, 0},
{4, TokenGasKind_Internal},
{0, 0},
{0, 0},
{4, TokenGasKind_Previous},
{4, TokenGasKind_Type},
{0, 0},
{0, 0},
{0, 0},
{4, TokenGasKind_Double},
{4, TokenGasKind_Set},
{0, 0},
{0, 0},
{0, 0},
{4, TokenGasKind_Sbttl},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{4, TokenGasKind_ifdef},
{4, TokenGasKind_Macro},
{0, 0},
{4, TokenGasKind_Endif},
{4, TokenGasKind_List},
{0, 0},
{4, TokenGasKind_Line},
{4, TokenGasKind_Protected},
{0, 0},
{0, 0},
{4, TokenGasKind_Fail},
{0, 0},
{4, TokenGasKind_Irp},
{0, 0},
{4, TokenGasKind_End},
{4, TokenGasKind_ifeq},
{4, TokenGasKind_Int},
{4, TokenGasKind_Purgem},
{0, 0},
{0, 0},
{4, TokenGasKind_ifnes},
{4, TokenGasKind_Quad},
{4, TokenGasKind_P2align},
{4, TokenGasKind_ifndef},
{4, TokenGasKind_ifnotdef},
{0, 0},
{4, TokenGasKind_Word},
{4, TokenGasKind_Stab},
{0, 0},
{4, TokenGasKind_ifeqs},
{4, TokenGasKind_global},
{0, 0},
{4, TokenGasKind_Noaltmacro},
{4, TokenGasKind_Eject},
{4, TokenGasKind_VTableEntry},
{4, TokenGasKind_Balign},
{0, 0},
{4, TokenGasKind_Endef},
{4, TokenGasKind_Endfunc},
{0, 0},
{0, 0},
{0, 0},
{4, TokenGasKind_ifgt},
{0, 0},
{4, TokenGasKind_Comm},
{0, 0},
{4, TokenGasKind_VTableInherit},
{0, 0},
{0, 0},
{0, 0},
};
i32 gas_main_keys_slot_count = 219;
u64 gas_main_keys_seed = 0x3762662741797c84;
u64 gas_registers_hash_array[488] = {
0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000,
0x0000000000000000,0x0000000000000000,0xee37f269111ee2f7,0x0000000000000000,
0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000,
0x0000000000000000,0x0000000000000000,0xee37f269111ed78f,0x0000000000000000,
0x6d643036b3b0cc99,0x6d643036b3b0cc99,0x0000000000000000,0x6d643036b3b0cc9b,
0x0000000000000000,0xee37f269111ee11d,0x0000000000000000,0x0000000000000000,
0x0000000000000000,0x0000000000000000,0x6d643036b3b0cca3,0x0000000000000000,
0x0000000000000000,0x6d643036b3b0cca5,0x6d643036b3b0cca7,0x0000000000000000,
0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000,
0x0000000000000000,0xee37f269111ed98d,0xe3900d4de2f05ab5,0x0000000000000000,
0xee37f26911117251,0xee37f26911117251,0xee37f26911117253,0x0000000000000000,
0x0000000000000000,0xee37f269111ed995,0x0000000000000000,0x0000000000000000,
0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000,
0xee37f2691111725d,0xee37f269111ee325,0x0000000000000000,0xee37f2691111725f,
0x0000000000000000,0xee37f269111ed7b9,0xe3900d4de2f02751,0x0000000000000000,
0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000,
0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000,
0xd1f60d7f9e600ed5,0x8b0e94b63ac50d55,0x0000000000000000,0x0000000000000000,
0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000,
0x0000000000000000,0x8b0e94b63ac50d5d,0x0000000000000000,0x0000000000000000,
0x0000000000000000,0xd1f60d7f9e600ee1,0x0000000000000000,0x0000000000000000,
0x0000000000000000,0x0000000000000000,0x0000000000000000,0xd1f60d7f838e5767,
0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000,
0x0000000000000000,0x0000000000000000,0x0000000000000000,0xd1f60d7f9e600eef,
0xee37f269111eb1c1,0xee37f269111eb1c1,0xee37f269111eb1c3,0x0000000000000000,
0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000,
0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000,
0x0000000000000000,0xd1f60d7f9e600d15,0x0000000000000000,0xd1f60d7f9e600d17,
0x0000000000000000,0x8b0e94b63ac50d81,0x0000000000000000,0x0000000000000000,
0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000,
0x0000000000000000,0xee37f269111ed9e1,0x0000000000000000,0x0000000000000000,
0x0000000000000000,0x6d643036b4f9e5a5,0x0000000000000000,0x0000000000000000,
0x0000000000000000,0x8b0e94b63ac50d91,0xe3900d4de2f02799,0x0000000000000000,
0x0000000000000000,0xee37f26911115615,0x0000000000000000,0xee37f26911115617,
0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000,
0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000,
0xd1f60d7f9e600d39,0xee37f2691111bb29,0x0000000000000000,0x0000000000000000,
0x0000000000000000,0x8b0e94b63ac50da5,0xee37f269111eb1f5,0xd1f60d7f9e7904e7,
0x0000000000000000,0x8b0e94b63ac50da9,0x0000000000000000,0xee37f269111eb1fb,
0xee37f269111eb1fd,0xee37f269111eb1fd,0xee37f269111eb1ff,0xee37f269111eb1ff,
0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000,
0x0000000000000000,0x6d643036b4f9e3e5,0x0000000000000000,0x0000000000000000,
0xee37f26911115639,0xe3900d4bbdb8e1a9,0xee37f26911116f01,0x6d643036b4f9e5d1,
0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000,
0x0000000000000000,0x8b0e94b63ac50dc1,0x0000000000000000,0x0000000000000000,
0x0000000000000000,0x8b0e94b63ac50dc5,0x0000000000000000,0x0000000000000000,
0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000,
0x0000000000000000,0x0000000000000000,0x8b0e94b63ac4f137,0x0000000000000000,
0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000,
0x0000000000000000,0xee37f269111ed845,0x8b0e94b63ac4f13d,0x0000000000000000,
0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000,
0x0000000000000000,0x0000000000000000,0x8b0e94b63ac50ddf,0x0000000000000000,
0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000,
0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000,
0x8b0e94b63ac50c01,0x0000000000000000,0x0000000000000000,0x0000000000000000,
0x0000000000000000,0x8b0e94b63ac50ded,0x8b0e94b63ac50c05,0x0000000000000000,
0x0000000000000000,0xd1f60d7f9e600f71,0x6d643036b4f9e421,0xd1f60d7f9e600f73,
0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000,
0xd1f60d7f9e8ade81,0xd1f60d7f9e8ade81,0x6d643036b4f9e241,0xd1f60d7f9e8ade83,
0xd1f60d7f9e8ade83,0x0000000000000000,0xd1f60d7f9e8ade87,0x0000000000000000,
0x0000000000000000,0xd1f60d7f9e8ade89,0x0000000000000000,0x0000000000000000,
0xd1f60d7f9e8ade8d,0x6d643036b4f9e435,0xd1f60d7f9e8ade8d,0xd1f60d7f9e8ade8f,
0xd1f60d7f9e8ade8f,0x0000000000000000,0xee37f26911115873,0x0000000000000000,
0x0000000000000000,0xee37f269111178dd,0xee37f26911115875,0xee37f26911115877,
0xee37f26911115879,0xee37f26911115879,0x0000000000000000,0xee37f2691111587b,
0x0000000000000000,0xee37f26911190b8d,0xee37f26911116f5f,0x0000000000000000,
0x0000000000000000,0x8b0e94b63ac50c31,0x0000000000000000,0x0000000000000000,
0x8b0e94b63ac50c35,0x0000000000000000,0x0000000000000000,0x0000000000000000,
0x0000000000000000,0x6d643036b4f9e269,0x0000000000000000,0x0000000000000000,
0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000,
0x0000000000000000,0xee37f26911116f71,0x0000000000000000,0x0000000000000000,
0x0000000000000000,0x6d643036b4f9e275,0x0000000000000000,0x0000000000000000,
0xd1f60d7f9e969541,0xd1f60d7f9e969541,0xd1f60d7f9e969543,0xd1f60d7f9e969543,
0x8b0e94b63ac50c4d,0x0000000000000000,0xd1f60d7f9e969547,0x0000000000000000,
0x0000000000000000,0xd1f60d7f9e969549,0x0000000000000000,0x0000000000000000,
0xd1f60d7f9e96954d,0xee37f26911116f85,0xd1f60d7f9e96954d,0xd1f60d7f9e96954f,
0xd1f60d7f9e96954f,0x0000000000000000,0x0000000000000000,0x0000000000000000,
0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000,
0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000,
0x0000000000000000,0x8b0e94b63ac4f1b5,0x8b0e94b63ac4f1b7,0x0000000000000000,
0x8b0e94b63ac50c69,0x0000000000000000,0x0000000000000000,0x0000000000000000,
0x0000000000000000,0xee37f269111156d5,0x0000000000000000,0x0000000000000000,
0x8b0e94b63ac4f1c1,0x0000000000000000,0x0000000000000000,0x0000000000000000,
0x0000000000000000,0x8b0e94b63ac50c75,0x0000000000000000,0x0000000000000000,
0x0000000000000000,0x8b0e94b63ac50c79,0x0000000000000000,0x0000000000000000,
0xee37f269111156e5,0x0000000000000000,0x0000000000000000,0x0000000000000000,
0xee37f269111ecf51,0xee37f269111ecf51,0xee37f269111ecf53,0xee37f269111156eb,
0x0000000000000000,0xee37f26911116fb5,0xee37f26911117d0d,0x0000000000000000,
0x0000000000000000,0xe3900d4de2f024a9,0x0000000000000000,0xee37f269111ecf5b,
0xee37f269111ecf5d,0xee37f269111ecf5d,0xee37f269111ecf5f,0xee37f269111ecf5f,
0x0000000000000000,0xee37f26911116dd9,0x0000000000000000,0x0000000000000000,
0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000,
0xd1f60d7f9e600e19,0xe3900f35d9e0a3a9,0x0000000000000000,0x0000000000000000,
0x0000000000000000,0xee37f26911116fcd,0x0000000000000000,0x0000000000000000,
0x6d64303d7004eba9,0x0000000000000000,0x0000000000000000,0x0000000000000000,
0x0000000000000000,0x0000000000000000,0xee37f269111149b7,0x0000000000000000,
0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000,
0x0000000000000000,0xd1f60d7f9e600e2d,0x0000000000000000,0x0000000000000000,
0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000,
0x0000000000000000,0x0000000000000000,0x0000000000000000,0xd1f60d7f9e600e37,
0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000,
0x0000000000000000,0xee37f269111149cd,0x0000000000000000,0x0000000000000000,
0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000,
0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000,
0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000,
0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000,
0x0000000000000000,0x6d643036b4f9e4e9,0x0000000000000000,0x0000000000000000,
0x0000000000000000,0xee37f269111928cd,0xd1f60d7f9e600e55,0x0000000000000000,
0x0000000000000000,0xee37f269111edb19,0x0000000000000000,0x0000000000000000,
0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000,
0x0000000000000000,0x6d643036b4f9e311,0xe3900d4de2f05a61,0x0000000000000000,
0xd1f60d7f9e600e65,0xe3900d4de2f02505,0x0000000000000000,0x0000000000000000,
0x0000000000000000,0x0000000000000000,0x0000000000000000,0xd1f60d7f9e600e6b,
0xd1f60d7f9e600c83,0x0000000000000000,0x0000000000000000,0x0000000000000000,
0x8b0e94b63ac50cf1,0x0000000000000000,0x0000000000000000,0x0000000000000000,
0xd1f60d7f9e600c8d,0x0000000000000000,0x0000000000000000,0x0000000000000000,
0x0000000000000000,0x8b0e94b63ac50cf9,0x0000000000000000,0x0000000000000000,
0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000,
0xd1f60d7f9e600e81,0x6d643036b4f9e519,0x6d643036b4f9e519,0x6d643036b4f9e51b,
0x0000000000000000,0xd1f60d7f9e600c9d,0x0000000000000000,0xd1f60d7f839751f7,
0x0000000000000000,0x0000000000000000,0x6d643036b4f9e523,0x0000000000000000,
0x0000000000000000,0x6d643036b4f9e525,0x6d643036b4f9e527,0x0000000000000000,
};
u8 gas_registers_key_array_6[] = {0x65,0x73,0x69,};
u8 gas_registers_key_array_14[] = {0x65,0x64,0x69,};
u8 gas_registers_key_array_16[] = {0x78,0x6d,0x6d,0x31,0x33,};
u8 gas_registers_key_array_17[] = {0x78,0x6d,0x6d,0x31,0x30,};
u8 gas_registers_key_array_19[] = {0x78,0x6d,0x6d,0x31,0x32,};
u8 gas_registers_key_array_21[] = {0x65,0x73,0x70,};
u8 gas_registers_key_array_26[] = {0x78,0x6d,0x6d,0x31,0x35,};
u8 gas_registers_key_array_29[] = {0x78,0x6d,0x6d,0x31,0x34,};
u8 gas_registers_key_array_30[] = {0x78,0x6d,0x6d,0x31,0x31,};
u8 gas_registers_key_array_37[] = {0x65,0x62,0x70,};
u8 gas_registers_key_array_38[] = {0x79,0x6d,0x6d,0x31,0x33,0x68,};
u8 gas_registers_key_array_40[] = {0x74,0x72,0x37,};
u8 gas_registers_key_array_41[] = {0x74,0x72,0x34,};
u8 gas_registers_key_array_42[] = {0x74,0x72,0x35,};
u8 gas_registers_key_array_45[] = {0x65,0x62,0x78,};
u8 gas_registers_key_array_52[] = {0x74,0x72,0x33,};
u8 gas_registers_key_array_53[] = {0x69,0x70,0x6c,};
u8 gas_registers_key_array_55[] = {0x74,0x72,0x36,};
u8 gas_registers_key_array_57[] = {0x65,0x64,0x78,};
u8 gas_registers_key_array_58[] = {0x79,0x6d,0x6d,0x31,0x31,0x68,};
u8 gas_registers_key_array_68[] = {0x72,0x31,0x33,0x77,};
u8 gas_registers_key_array_69[] = {0x62,0x78,};
u8 gas_registers_key_array_77[] = {0x62,0x70,};
u8 gas_registers_key_array_81[] = {0x72,0x31,0x33,0x64,};
u8 gas_registers_key_array_87[] = {0x69,0x64,0x74,0x72,};
u8 gas_registers_key_array_95[] = {0x72,0x31,0x33,0x62,};
u8 gas_registers_key_array_96[] = {0x63,0x72,0x37,};
u8 gas_registers_key_array_97[] = {0x63,0x72,0x34,};
u8 gas_registers_key_array_98[] = {0x63,0x72,0x35,};
u8 gas_registers_key_array_109[] = {0x72,0x31,0x34,0x64,};
u8 gas_registers_key_array_111[] = {0x72,0x31,0x34,0x62,};
u8 gas_registers_key_array_113[] = {0x61,0x78,};
u8 gas_registers_key_array_121[] = {0x65,0x61,0x78,};
u8 gas_registers_key_array_125[] = {0x79,0x6d,0x6d,0x32,0x68,};
u8 gas_registers_key_array_129[] = {0x61,0x68,};
u8 gas_registers_key_array_130[] = {0x79,0x6d,0x6d,0x31,0x34,0x68,};
u8 gas_registers_key_array_133[] = {0x72,0x38,0x64,};
u8 gas_registers_key_array_135[] = {0x72,0x38,0x62,};
u8 gas_registers_key_array_144[] = {0x72,0x31,0x34,0x77,};
u8 gas_registers_key_array_145[] = {0x78,0x73,0x73,};
u8 gas_registers_key_array_149[] = {0x62,0x68,};
u8 gas_registers_key_array_150[] = {0x63,0x72,0x38,};
u8 gas_registers_key_array_151[] = {0x6c,0x64,0x74,0x72,};
u8 gas_registers_key_array_153[] = {0x62,0x6c,};
u8 gas_registers_key_array_155[] = {0x63,0x72,0x32,};
u8 gas_registers_key_array_156[] = {0x63,0x72,0x33,};
u8 gas_registers_key_array_157[] = {0x63,0x72,0x30,};
u8 gas_registers_key_array_158[] = {0x63,0x72,0x31,};
u8 gas_registers_key_array_159[] = {0x63,0x72,0x36,};
u8 gas_registers_key_array_165[] = {0x79,0x6d,0x6d,0x36,0x68,};
u8 gas_registers_key_array_168[] = {0x72,0x38,0x77,};
u8 gas_registers_key_array_169[] = {0x72,0x66,0x6c,0x61,0x67,0x73,};
u8 gas_registers_key_array_170[] = {0x72,0x61,0x78,};
u8 gas_registers_key_array_171[] = {0x79,0x6d,0x6d,0x31,0x68,};
u8 gas_registers_key_array_177[] = {0x64,0x68,};
u8 gas_registers_key_array_181[] = {0x64,0x6c,};
u8 gas_registers_key_array_190[] = {0x73,0x69,};
u8 gas_registers_key_array_197[] = {0x65,0x63,0x78,};
u8 gas_registers_key_array_198[] = {0x73,0x70,};
u8 gas_registers_key_array_206[] = {0x64,0x69,};
u8 gas_registers_key_array_216[] = {0x63,0x73,};
u8 gas_registers_key_array_221[] = {0x61,0x6c,};
u8 gas_registers_key_array_222[] = {0x63,0x78,};
u8 gas_registers_key_array_225[] = {0x72,0x31,0x32,0x64,};
u8 gas_registers_key_array_226[] = {0x79,0x6d,0x6d,0x30,0x68,};
u8 gas_registers_key_array_227[] = {0x72,0x31,0x32,0x62,};
u8 gas_registers_key_array_232[] = {0x79,0x6d,0x6d,0x33,};
u8 gas_registers_key_array_233[] = {0x79,0x6d,0x6d,0x30,};
u8 gas_registers_key_array_234[] = {0x79,0x6d,0x6d,0x38,0x68,};
u8 gas_registers_key_array_235[] = {0x79,0x6d,0x6d,0x35,};
u8 gas_registers_key_array_236[] = {0x79,0x6d,0x6d,0x32,};
u8 gas_registers_key_array_238[] = {0x79,0x6d,0x6d,0x31,};
u8 gas_registers_key_array_241[] = {0x79,0x6d,0x6d,0x38,};
u8 gas_registers_key_array_244[] = {0x79,0x6d,0x6d,0x37,};
u8 gas_registers_key_array_245[] = {0x79,0x6d,0x6d,0x33,0x68,};
u8 gas_registers_key_array_246[] = {0x79,0x6d,0x6d,0x34,};
u8 gas_registers_key_array_247[] = {0x79,0x6d,0x6d,0x39,};
u8 gas_registers_key_array_248[] = {0x79,0x6d,0x6d,0x36,};
u8 gas_registers_key_array_250[] = {0x72,0x31,0x35,};
u8 gas_registers_key_array_253[] = {0x73,0x69,0x6c,};
u8 gas_registers_key_array_254[] = {0x72,0x31,0x34,};
u8 gas_registers_key_array_255[] = {0x72,0x31,0x31,};
u8 gas_registers_key_array_256[] = {0x72,0x31,0x33,};
u8 gas_registers_key_array_257[] = {0x72,0x31,0x30,};
u8 gas_registers_key_array_259[] = {0x72,0x31,0x32,};
u8 gas_registers_key_array_261[] = {0x62,0x70,0x6c,};
u8 gas_registers_key_array_262[] = {0x72,0x64,0x69,};
u8 gas_registers_key_array_265[] = {0x64,0x78,};
u8 gas_registers_key_array_268[] = {0x64,0x73,};
u8 gas_registers_key_array_273[] = {0x79,0x6d,0x6d,0x34,0x68,};
u8 gas_registers_key_array_281[] = {0x72,0x64,0x78,};
u8 gas_registers_key_array_285[] = {0x79,0x6d,0x6d,0x37,0x68,};
u8 gas_registers_key_array_288[] = {0x78,0x6d,0x6d,0x33,};
u8 gas_registers_key_array_289[] = {0x78,0x6d,0x6d,0x30,};
u8 gas_registers_key_array_290[] = {0x78,0x6d,0x6d,0x35,};
u8 gas_registers_key_array_291[] = {0x78,0x6d,0x6d,0x32,};
u8 gas_registers_key_array_292[] = {0x66,0x73,};
u8 gas_registers_key_array_294[] = {0x78,0x6d,0x6d,0x31,};
u8 gas_registers_key_array_297[] = {0x78,0x6d,0x6d,0x38,};
u8 gas_registers_key_array_300[] = {0x78,0x6d,0x6d,0x37,};
u8 gas_registers_key_array_301[] = {0x72,0x63,0x78,};
u8 gas_registers_key_array_302[] = {0x78,0x6d,0x6d,0x34,};
u8 gas_registers_key_array_303[] = {0x78,0x6d,0x6d,0x39,};
u8 gas_registers_key_array_304[] = {0x78,0x6d,0x6d,0x36,};
u8 gas_registers_key_array_317[] = {0x72,0x38,};
u8 gas_registers_key_array_318[] = {0x72,0x39,};
u8 gas_registers_key_array_320[] = {0x67,0x73,};
u8 gas_registers_key_array_325[] = {0x72,0x39,0x64,};
u8 gas_registers_key_array_328[] = {0x73,0x73,};
u8 gas_registers_key_array_333[] = {0x63,0x68,};
u8 gas_registers_key_array_337[] = {0x63,0x6c,};
u8 gas_registers_key_array_340[] = {0x72,0x39,0x77,};
u8 gas_registers_key_array_344[] = {0x64,0x72,0x37,};
u8 gas_registers_key_array_345[] = {0x64,0x72,0x34,};
u8 gas_registers_key_array_346[] = {0x64,0x72,0x35,};
u8 gas_registers_key_array_347[] = {0x72,0x39,0x62,};
u8 gas_registers_key_array_349[] = {0x72,0x62,0x78,};
u8 gas_registers_key_array_350[] = {0x73,0x70,0x6c,};
u8 gas_registers_key_array_353[] = {0x79,0x6d,0x6d,0x31,0x35,0x68,};
u8 gas_registers_key_array_355[] = {0x64,0x72,0x32,};
u8 gas_registers_key_array_356[] = {0x64,0x72,0x33,};
u8 gas_registers_key_array_357[] = {0x64,0x72,0x30,};
u8 gas_registers_key_array_358[] = {0x64,0x72,0x31,};
u8 gas_registers_key_array_359[] = {0x64,0x72,0x36,};
u8 gas_registers_key_array_361[] = {0x72,0x69,0x70,};
u8 gas_registers_key_array_368[] = {0x72,0x31,0x30,0x77,};
u8 gas_registers_key_array_369[] = {0x65,0x66,0x6c,0x61,0x67,0x73,};
u8 gas_registers_key_array_373[] = {0x72,0x62,0x70,};
u8 gas_registers_key_array_376[] = {0x66,0x6c,0x61,0x67,0x73,};
u8 gas_registers_key_array_382[] = {0x72,0x73,0x69,};
u8 gas_registers_key_array_389[] = {0x72,0x31,0x30,0x64,};
u8 gas_registers_key_array_399[] = {0x72,0x31,0x30,0x62,};
u8 gas_registers_key_array_405[] = {0x72,0x73,0x70,};
u8 gas_registers_key_array_425[] = {0x79,0x6d,0x6d,0x35,0x68,};
u8 gas_registers_key_array_429[] = {0x64,0x69,0x6c,};
u8 gas_registers_key_array_430[] = {0x72,0x31,0x31,0x64,};
u8 gas_registers_key_array_433[] = {0x65,0x69,0x70,};
u8 gas_registers_key_array_441[] = {0x79,0x6d,0x6d,0x39,0x68,};
u8 gas_registers_key_array_442[] = {0x79,0x6d,0x6d,0x31,0x30,0x68,};
u8 gas_registers_key_array_444[] = {0x72,0x31,0x31,0x77,};
u8 gas_registers_key_array_445[] = {0x79,0x6d,0x6d,0x31,0x32,0x68,};
u8 gas_registers_key_array_451[] = {0x72,0x31,0x31,0x62,};
u8 gas_registers_key_array_452[] = {0x72,0x31,0x35,0x62,};
u8 gas_registers_key_array_456[] = {0x65,0x73,};
u8 gas_registers_key_array_460[] = {0x72,0x31,0x35,0x77,};
u8 gas_registers_key_array_465[] = {0x69,0x70,};
u8 gas_registers_key_array_472[] = {0x72,0x31,0x32,0x77,};
u8 gas_registers_key_array_473[] = {0x79,0x6d,0x6d,0x31,0x33,};
u8 gas_registers_key_array_474[] = {0x79,0x6d,0x6d,0x31,0x30,};
u8 gas_registers_key_array_475[] = {0x79,0x6d,0x6d,0x31,0x32,};
u8 gas_registers_key_array_477[] = {0x72,0x31,0x35,0x64,};
u8 gas_registers_key_array_479[] = {0x67,0x64,0x74,0x72,};
u8 gas_registers_key_array_482[] = {0x79,0x6d,0x6d,0x31,0x35,};
u8 gas_registers_key_array_485[] = {0x79,0x6d,0x6d,0x31,0x34,};
u8 gas_registers_key_array_486[] = {0x79,0x6d,0x6d,0x31,0x31,};
String_Const_u8 gas_registers_key_array[488] = {
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{gas_registers_key_array_6, 3},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{gas_registers_key_array_14, 3},
{0, 0},
{gas_registers_key_array_16, 5},
{gas_registers_key_array_17, 5},
{0, 0},
{gas_registers_key_array_19, 5},
{0, 0},
{gas_registers_key_array_21, 3},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{gas_registers_key_array_26, 5},
{0, 0},
{0, 0},
{gas_registers_key_array_29, 5},
{gas_registers_key_array_30, 5},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{gas_registers_key_array_37, 3},
{gas_registers_key_array_38, 6},
{0, 0},
{gas_registers_key_array_40, 3},
{gas_registers_key_array_41, 3},
{gas_registers_key_array_42, 3},
{0, 0},
{0, 0},
{gas_registers_key_array_45, 3},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{gas_registers_key_array_52, 3},
{gas_registers_key_array_53, 3},
{0, 0},
{gas_registers_key_array_55, 3},
{0, 0},
{gas_registers_key_array_57, 3},
{gas_registers_key_array_58, 6},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{gas_registers_key_array_68, 4},
{gas_registers_key_array_69, 2},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{gas_registers_key_array_77, 2},
{0, 0},
{0, 0},
{0, 0},
{gas_registers_key_array_81, 4},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{gas_registers_key_array_87, 4},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{gas_registers_key_array_95, 4},
{gas_registers_key_array_96, 3},
{gas_registers_key_array_97, 3},
{gas_registers_key_array_98, 3},
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
{gas_registers_key_array_109, 4},
{0, 0},
{gas_registers_key_array_111, 4},
{0, 0},
{gas_registers_key_array_113, 2},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{gas_registers_key_array_121, 3},
{0, 0},
{0, 0},
{0, 0},
{gas_registers_key_array_125, 5},
{0, 0},
{0, 0},
{0, 0},
{gas_registers_key_array_129, 2},
{gas_registers_key_array_130, 6},
{0, 0},
{0, 0},
{gas_registers_key_array_133, 3},
{0, 0},
{gas_registers_key_array_135, 3},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{gas_registers_key_array_144, 4},
{gas_registers_key_array_145, 3},
{0, 0},
{0, 0},
{0, 0},
{gas_registers_key_array_149, 2},
{gas_registers_key_array_150, 3},
{gas_registers_key_array_151, 4},
{0, 0},
{gas_registers_key_array_153, 2},
{0, 0},
{gas_registers_key_array_155, 3},
{gas_registers_key_array_156, 3},
{gas_registers_key_array_157, 3},
{gas_registers_key_array_158, 3},
{gas_registers_key_array_159, 3},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{gas_registers_key_array_165, 5},
{0, 0},
{0, 0},
{gas_registers_key_array_168, 3},
{gas_registers_key_array_169, 6},
{gas_registers_key_array_170, 3},
{gas_registers_key_array_171, 5},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{gas_registers_key_array_177, 2},
{0, 0},
{0, 0},
{0, 0},
{gas_registers_key_array_181, 2},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{gas_registers_key_array_190, 2},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{gas_registers_key_array_197, 3},
{gas_registers_key_array_198, 2},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{gas_registers_key_array_206, 2},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{gas_registers_key_array_216, 2},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{gas_registers_key_array_221, 2},
{gas_registers_key_array_222, 2},
{0, 0},
{0, 0},
{gas_registers_key_array_225, 4},
{gas_registers_key_array_226, 5},
{gas_registers_key_array_227, 4},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{gas_registers_key_array_232, 4},
{gas_registers_key_array_233, 4},
{gas_registers_key_array_234, 5},
{gas_registers_key_array_235, 4},
{gas_registers_key_array_236, 4},
{0, 0},
{gas_registers_key_array_238, 4},
{0, 0},
{0, 0},
{gas_registers_key_array_241, 4},
{0, 0},
{0, 0},
{gas_registers_key_array_244, 4},
{gas_registers_key_array_245, 5},
{gas_registers_key_array_246, 4},
{gas_registers_key_array_247, 4},
{gas_registers_key_array_248, 4},
{0, 0},
{gas_registers_key_array_250, 3},
{0, 0},
{0, 0},
{gas_registers_key_array_253, 3},
{gas_registers_key_array_254, 3},
{gas_registers_key_array_255, 3},
{gas_registers_key_array_256, 3},
{gas_registers_key_array_257, 3},
{0, 0},
{gas_registers_key_array_259, 3},
{0, 0},
{gas_registers_key_array_261, 3},
{gas_registers_key_array_262, 3},
{0, 0},
{0, 0},
{gas_registers_key_array_265, 2},
{0, 0},
{0, 0},
{gas_registers_key_array_268, 2},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{gas_registers_key_array_273, 5},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{gas_registers_key_array_281, 3},
{0, 0},
{0, 0},
{0, 0},
{gas_registers_key_array_285, 5},
{0, 0},
{0, 0},
{gas_registers_key_array_288, 4},
{gas_registers_key_array_289, 4},
{gas_registers_key_array_290, 4},
{gas_registers_key_array_291, 4},
{gas_registers_key_array_292, 2},
{0, 0},
{gas_registers_key_array_294, 4},
{0, 0},
{0, 0},
{gas_registers_key_array_297, 4},
{0, 0},
{0, 0},
{gas_registers_key_array_300, 4},
{gas_registers_key_array_301, 3},
{gas_registers_key_array_302, 4},
{gas_registers_key_array_303, 4},
{gas_registers_key_array_304, 4},
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
{gas_registers_key_array_317, 2},
{gas_registers_key_array_318, 2},
{0, 0},
{gas_registers_key_array_320, 2},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{gas_registers_key_array_325, 3},
{0, 0},
{0, 0},
{gas_registers_key_array_328, 2},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{gas_registers_key_array_333, 2},
{0, 0},
{0, 0},
{0, 0},
{gas_registers_key_array_337, 2},
{0, 0},
{0, 0},
{gas_registers_key_array_340, 3},
{0, 0},
{0, 0},
{0, 0},
{gas_registers_key_array_344, 3},
{gas_registers_key_array_345, 3},
{gas_registers_key_array_346, 3},
{gas_registers_key_array_347, 3},
{0, 0},
{gas_registers_key_array_349, 3},
{gas_registers_key_array_350, 3},
{0, 0},
{0, 0},
{gas_registers_key_array_353, 6},
{0, 0},
{gas_registers_key_array_355, 3},
{gas_registers_key_array_356, 3},
{gas_registers_key_array_357, 3},
{gas_registers_key_array_358, 3},
{gas_registers_key_array_359, 3},
{0, 0},
{gas_registers_key_array_361, 3},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{gas_registers_key_array_368, 4},
{gas_registers_key_array_369, 6},
{0, 0},
{0, 0},
{0, 0},
{gas_registers_key_array_373, 3},
{0, 0},
{0, 0},
{gas_registers_key_array_376, 5},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{gas_registers_key_array_382, 3},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{gas_registers_key_array_389, 4},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{gas_registers_key_array_399, 4},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{gas_registers_key_array_405, 3},
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
{gas_registers_key_array_425, 5},
{0, 0},
{0, 0},
{0, 0},
{gas_registers_key_array_429, 3},
{gas_registers_key_array_430, 4},
{0, 0},
{0, 0},
{gas_registers_key_array_433, 3},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{gas_registers_key_array_441, 5},
{gas_registers_key_array_442, 6},
{0, 0},
{gas_registers_key_array_444, 4},
{gas_registers_key_array_445, 6},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{gas_registers_key_array_451, 4},
{gas_registers_key_array_452, 4},
{0, 0},
{0, 0},
{0, 0},
{gas_registers_key_array_456, 2},
{0, 0},
{0, 0},
{0, 0},
{gas_registers_key_array_460, 4},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{gas_registers_key_array_465, 2},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{gas_registers_key_array_472, 4},
{gas_registers_key_array_473, 5},
{gas_registers_key_array_474, 5},
{gas_registers_key_array_475, 5},
{0, 0},
{gas_registers_key_array_477, 4},
{0, 0},
{gas_registers_key_array_479, 4},
{0, 0},
{0, 0},
{gas_registers_key_array_482, 5},
{0, 0},
{0, 0},
{gas_registers_key_array_485, 5},
{gas_registers_key_array_486, 5},
{0, 0},
};
Lexeme_Table_Value gas_registers_value_array[488] = {
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{4, TokenGasKind_esi},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{4, TokenGasKind_edi},
{0, 0},
{4, TokenGasKind_xmm13},
{4, TokenGasKind_xmm10},
{0, 0},
{4, TokenGasKind_xmm12},
{0, 0},
{4, TokenGasKind_esp},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{4, TokenGasKind_xmm15},
{0, 0},
{0, 0},
{4, TokenGasKind_xmm14},
{4, TokenGasKind_xmm11},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{4, TokenGasKind_ebp},
{4, TokenGasKind_ymm13h},
{0, 0},
{4, TokenGasKind_tr7},
{4, TokenGasKind_tr4},
{4, TokenGasKind_tr5},
{0, 0},
{0, 0},
{4, TokenGasKind_ebx},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{4, TokenGasKind_tr3},
{4, TokenGasKind_ipl},
{0, 0},
{4, TokenGasKind_tr6},
{0, 0},
{4, TokenGasKind_edx},
{4, TokenGasKind_ymm11h},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{4, TokenGasKind_r13w},
{4, TokenGasKind_bx},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{4, TokenGasKind_bp},
{0, 0},
{0, 0},
{0, 0},
{4, TokenGasKind_r13d},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{4, TokenGasKind_idtr},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{4, TokenGasKind_r13b},
{4, TokenGasKind_cr7},
{4, TokenGasKind_cr4},
{4, TokenGasKind_cr5},
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
{4, TokenGasKind_r14d},
{0, 0},
{4, TokenGasKind_r14b},
{0, 0},
{4, TokenGasKind_ax},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{4, TokenGasKind_eax},
{0, 0},
{0, 0},
{0, 0},
{4, TokenGasKind_ymm2h},
{0, 0},
{0, 0},
{0, 0},
{4, TokenGasKind_ah},
{4, TokenGasKind_ymm14h},
{0, 0},
{0, 0},
{4, TokenGasKind_r8d},
{0, 0},
{4, TokenGasKind_r8b},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{4, TokenGasKind_r14w},
{4, TokenGasKind_xss},
{0, 0},
{0, 0},
{0, 0},
{4, TokenGasKind_bh},
{4, TokenGasKind_cr8},
{4, TokenGasKind_ldtr},
{0, 0},
{4, TokenGasKind_bl},
{0, 0},
{4, TokenGasKind_cr2},
{4, TokenGasKind_cr3},
{4, TokenGasKind_cr0},
{4, TokenGasKind_cr1},
{4, TokenGasKind_cr6},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{4, TokenGasKind_ymm6h},
{0, 0},
{0, 0},
{4, TokenGasKind_r8w},
{4, TokenGasKind_rflags},
{4, TokenGasKind_rax},
{4, TokenGasKind_ymm1h},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{4, TokenGasKind_dh},
{0, 0},
{0, 0},
{0, 0},
{4, TokenGasKind_dl},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{4, TokenGasKind_si},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{4, TokenGasKind_ecx},
{4, TokenGasKind_sp},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{4, TokenGasKind_di},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{4, TokenGasKind_cs},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{4, TokenGasKind_al},
{4, TokenGasKind_cx},
{0, 0},
{0, 0},
{4, TokenGasKind_r12d},
{4, TokenGasKind_ymm0h},
{4, TokenGasKind_r12b},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{4, TokenGasKind_ymm3},
{4, TokenGasKind_ymm0},
{4, TokenGasKind_ymm8h},
{4, TokenGasKind_ymm5},
{4, TokenGasKind_ymm2},
{0, 0},
{4, TokenGasKind_ymm1},
{0, 0},
{0, 0},
{4, TokenGasKind_ymm8},
{0, 0},
{0, 0},
{4, TokenGasKind_ymm7},
{4, TokenGasKind_ymm3h},
{4, TokenGasKind_ymm4},
{4, TokenGasKind_ymm9},
{4, TokenGasKind_ymm6},
{0, 0},
{4, TokenGasKind_r15},
{0, 0},
{0, 0},
{4, TokenGasKind_sil},
{4, TokenGasKind_r14},
{4, TokenGasKind_r11},
{4, TokenGasKind_r13},
{4, TokenGasKind_r10},
{0, 0},
{4, TokenGasKind_r12},
{0, 0},
{4, TokenGasKind_bpl},
{4, TokenGasKind_rdi},
{0, 0},
{0, 0},
{4, TokenGasKind_dx},
{0, 0},
{0, 0},
{4, TokenGasKind_ds},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{4, TokenGasKind_ymm4h},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{4, TokenGasKind_rdx},
{0, 0},
{0, 0},
{0, 0},
{4, TokenGasKind_ymm7h},
{0, 0},
{0, 0},
{4, TokenGasKind_xmm3},
{4, TokenGasKind_xmm0},
{4, TokenGasKind_xmm5},
{4, TokenGasKind_xmm2},
{4, TokenGasKind_fs},
{0, 0},
{4, TokenGasKind_xmm1},
{0, 0},
{0, 0},
{4, TokenGasKind_xmm8},
{0, 0},
{0, 0},
{4, TokenGasKind_xmm7},
{4, TokenGasKind_rcx},
{4, TokenGasKind_xmm4},
{4, TokenGasKind_xmm9},
{4, TokenGasKind_xmm6},
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
{4, TokenGasKind_r8},
{4, TokenGasKind_r9},
{0, 0},
{4, TokenGasKind_gs},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{4, TokenGasKind_r9d},
{0, 0},
{0, 0},
{4, TokenGasKind_ss},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{4, TokenGasKind_ch},
{0, 0},
{0, 0},
{0, 0},
{4, TokenGasKind_cl},
{0, 0},
{0, 0},
{4, TokenGasKind_r9w},
{0, 0},
{0, 0},
{0, 0},
{4, TokenGasKind_dr7},
{4, TokenGasKind_dr4},
{4, TokenGasKind_dr5},
{4, TokenGasKind_r9b},
{0, 0},
{4, TokenGasKind_rbx},
{4, TokenGasKind_spl},
{0, 0},
{0, 0},
{4, TokenGasKind_ymm15h},
{0, 0},
{4, TokenGasKind_dr2},
{4, TokenGasKind_dr3},
{4, TokenGasKind_dr0},
{4, TokenGasKind_dr1},
{4, TokenGasKind_dr6},
{0, 0},
{4, TokenGasKind_rip},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{4, TokenGasKind_r10w},
{4, TokenGasKind_eflags},
{0, 0},
{0, 0},
{0, 0},
{4, TokenGasKind_rbp},
{0, 0},
{0, 0},
{4, TokenGasKind_flags},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{4, TokenGasKind_rsi},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{4, TokenGasKind_r10d},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{4, TokenGasKind_r10b},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{4, TokenGasKind_rsp},
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
{4, TokenGasKind_ymm5h},
{0, 0},
{0, 0},
{0, 0},
{4, TokenGasKind_dil},
{4, TokenGasKind_r11d},
{0, 0},
{0, 0},
{4, TokenGasKind_eip},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{4, TokenGasKind_ymm9h},
{4, TokenGasKind_ymm10h},
{0, 0},
{4, TokenGasKind_r11w},
{4, TokenGasKind_ymm12h},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{4, TokenGasKind_r11b},
{4, TokenGasKind_r15b},
{0, 0},
{0, 0},
{0, 0},
{4, TokenGasKind_es},
{0, 0},
{0, 0},
{0, 0},
{4, TokenGasKind_r15w},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{4, TokenGasKind_ip},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{4, TokenGasKind_r12w},
{4, TokenGasKind_ymm13},
{4, TokenGasKind_ymm10},
{4, TokenGasKind_ymm12},
{0, 0},
{4, TokenGasKind_r15d},
{0, 0},
{4, TokenGasKind_gdtr},
{0, 0},
{0, 0},
{4, TokenGasKind_ymm15},
{0, 0},
{0, 0},
{4, TokenGasKind_ymm14},
{4, TokenGasKind_ymm11},
{0, 0},
};
i32 gas_registers_slot_count = 488;
u64 gas_registers_seed = 0x58dd20dfa071f2cd;
struct Lex_State_Gas{
u32 flags_ZF0;
u8 *base;
u8 *delim_first;
u8 *delim_one_past_last;
u8 *emit_ptr;
u8 *ptr;
u8 *opl_ptr;
};
internal void
lex_full_input_gas_init(Lex_State_Gas *state_ptr, String_Const_u8 input){
state_ptr->flags_ZF0 = 0;
state_ptr->base = input.str;
state_ptr->delim_first = input.str;
state_ptr->delim_one_past_last = input.str;
state_ptr->emit_ptr = input.str;
state_ptr->ptr = input.str;
state_ptr->opl_ptr = input.str + input.size;
}
internal b32
lex_full_input_gas_breaks(Arena *arena, Token_List *list, Lex_State_Gas *state_ptr, u64 max){
b32 result = false;
u64 emit_counter = 0;
Lex_State_Gas state;
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
token.sub_kind = TokenGasKind_EOF;
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
case 0x26:case 0x2a:case 0x2c:case 0x3b:case 0x3c:case 0x3d:case 0x3e:
case 0x3f:case 0x40:case 0x5c:case 0x5e:case 0x60:case 0x7b:case 0x7c:
case 0x7d:case 0x7f:
{
state.ptr += 1;
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
do{
token.sub_kind = TokenGasKind_LexError;
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
case 0x23:
{
state.ptr += 1;
goto state_label_20; // comment_line
}break;
case 0x24:
{
state.ptr += 1;
goto state_label_23; // value_first
}break;
case 0x25:
{
state.ptr += 1;
state.delim_first = state.ptr;
goto state_label_22; // register_rest
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
token.sub_kind = TokenGasKind_ParenOp;
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
token.sub_kind = TokenGasKind_ParenCl;
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
token.sub_kind = TokenGasKind_Plus;
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
token.sub_kind = TokenGasKind_Minus;
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
state.delim_first = state.ptr;
goto state_label_4; // operator_or_fnumber_dot
}break;
case 0x2f:
{
state.ptr += 1;
goto state_label_18; // comment_block_first
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
token.sub_kind = TokenGasKind_Colon;
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
token.sub_kind = TokenGasKind_BrackOp;
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
token.sub_kind = TokenGasKind_BrackCl;
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
token.sub_kind = TokenGasKind_Tilde;
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
token.sub_kind = TokenGasKind_Identifier;
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
token.sub_kind = TokenGasKind_Identifier;
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
token.sub_kind = TokenGasKind_Whitespace;
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
token.sub_kind = TokenGasKind_Whitespace;
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
token.sub_kind = TokenGasKind_Dot;
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
token.sub_kind = TokenGasKind_Dot;
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
goto state_label_21; // keyword_rest
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
token.sub_kind = TokenGasKind_LiteralInteger;
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
token.sub_kind = TokenGasKind_LiteralInteger;
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
case 0x37:case 0x38:case 0x39:
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
token.sub_kind = TokenGasKind_LiteralInteger;
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
token.sub_kind = TokenGasKind_LiteralInteger;
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
token.sub_kind = TokenGasKind_LiteralFloat;
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
token.sub_kind = TokenGasKind_LiteralFloat;
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
token.sub_kind = TokenGasKind_LiteralFloat;
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
token.sub_kind = TokenGasKind_LiteralFloat;
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
token.sub_kind = TokenGasKind_LiteralFloat;
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
token.sub_kind = TokenGasKind_LiteralFloat;
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
token.sub_kind = TokenGasKind_LiteralFloat;
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
token.sub_kind = TokenGasKind_LiteralFloat;
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
token.sub_kind = TokenGasKind_LexError;
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
token.sub_kind = TokenGasKind_LexError;
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
token.sub_kind = TokenGasKind_LexError;
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
token.sub_kind = TokenGasKind_LexError;
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
token.sub_kind = TokenGasKind_LiteralIntegerHex;
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
token.sub_kind = TokenGasKind_LiteralIntegerHex;
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
token.sub_kind = TokenGasKind_LiteralIntegerOct;
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
token.sub_kind = TokenGasKind_LiteralIntegerOct;
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
token.sub_kind = TokenGasKind_LiteralIntegerBin;
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
token.sub_kind = TokenGasKind_LiteralIntegerBin;
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
token.sub_kind = TokenGasKind_LexError;
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
token.sub_kind = TokenGasKind_EOF;
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
token.sub_kind = TokenGasKind_LiteralString;
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
token.sub_kind = TokenGasKind_LiteralCharacter;
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
state_label_17: // comment_block
if (state.ptr == state.opl_ptr){
if ((true)){
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
do{
token.sub_kind = TokenGasKind_BlockComment;
token.kind = 3;
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
token.sub_kind = TokenGasKind_EOF;
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
goto state_label_17; // comment_block
}break;
case 0x2a:
{
state.ptr += 1;
goto state_label_19; // comment_block_try_close
}break;
}
}
{
state_label_18: // comment_block_first
if (state.ptr == state.opl_ptr){
if ((true)){
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
do{
token.sub_kind = TokenGasKind_LexError;
token.kind = 2;
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
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
do{
token.sub_kind = TokenGasKind_LexError;
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
case 0x2a:
{
state.ptr += 1;
goto state_label_17; // comment_block
}break;
}
}
{
state_label_19: // comment_block_try_close
if (state.ptr == state.opl_ptr){
if ((true)){
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
do{
token.sub_kind = TokenGasKind_BlockComment;
token.kind = 3;
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
token.sub_kind = TokenGasKind_EOF;
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
goto state_label_17; // comment_block
}break;
case 0x2a:
{
state.ptr += 1;
goto state_label_19; // comment_block_try_close
}break;
case 0x2f:
{
state.ptr += 1;
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
do{
token.sub_kind = TokenGasKind_BlockComment;
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
state_label_20: // comment_line
if (state.ptr == state.opl_ptr){
if ((true)){
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
do{
token.sub_kind = TokenGasKind_LineComment;
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
goto state_label_20; // comment_line
}break;
case 0x0a:
{
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
do{
token.sub_kind = TokenGasKind_LineComment;
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
state_label_21: // keyword_rest
if (state.ptr == state.opl_ptr){
if ((true)){
state.delim_one_past_last = state.ptr;
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
do{
Lexeme_Table_Lookup lookup = lexeme_table_lookup(gas_main_keys_hash_array, gas_main_keys_key_array, gas_main_keys_value_array, gas_main_keys_slot_count, gas_main_keys_seed, state.delim_first, (state.delim_one_past_last - state.delim_first));
if (lookup.found_match){
token.kind = lookup.base_kind;
token.sub_kind = lookup.sub_kind;
break;
}
token.sub_kind = TokenGasKind_Identifier;
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
case 0x2a:case 0x2b:case 0x2c:case 0x2d:case 0x2e:case 0x2f:case 0x30:
case 0x31:case 0x32:case 0x33:case 0x34:case 0x35:case 0x36:case 0x37:
case 0x38:case 0x39:case 0x3a:case 0x3b:case 0x3c:case 0x3d:case 0x3e:
case 0x3f:case 0x40:case 0x5b:case 0x5c:case 0x5d:case 0x5e:case 0x60:
case 0x7b:case 0x7c:case 0x7d:case 0x7e:case 0x7f:
{
state.delim_one_past_last = state.ptr;
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
do{
Lexeme_Table_Lookup lookup = lexeme_table_lookup(gas_main_keys_hash_array, gas_main_keys_key_array, gas_main_keys_value_array, gas_main_keys_slot_count, gas_main_keys_seed, state.delim_first, (state.delim_one_past_last - state.delim_first));
if (lookup.found_match){
token.kind = lookup.base_kind;
token.sub_kind = lookup.sub_kind;
break;
}
token.sub_kind = TokenGasKind_Identifier;
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
goto state_label_21; // keyword_rest
}break;
}
}
{
state_label_22: // register_rest
if (state.ptr == state.opl_ptr){
if ((true)){
state.delim_one_past_last = state.ptr;
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
do{
Lexeme_Table_Lookup lookup = lexeme_table_lookup(gas_registers_hash_array, gas_registers_key_array, gas_registers_value_array, gas_registers_slot_count, gas_registers_seed, state.delim_first, (state.delim_one_past_last - state.delim_first));
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
Lexeme_Table_Lookup lookup = lexeme_table_lookup(gas_registers_hash_array, gas_registers_key_array, gas_registers_value_array, gas_registers_slot_count, gas_registers_seed, state.delim_first, (state.delim_one_past_last - state.delim_first));
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
goto state_label_22; // register_rest
}break;
}
}
{
state_label_23: // value_first
if (state.ptr == state.opl_ptr){
if ((true)){
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
do{
token.sub_kind = TokenGasKind_LexError;
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
token.sub_kind = TokenGasKind_LexError;
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
case 0x41:case 0x42:case 0x43:case 0x44:case 0x45:case 0x46:case 0x47:
case 0x48:case 0x49:case 0x4a:case 0x4b:case 0x4c:case 0x4d:case 0x4e:
case 0x4f:case 0x50:case 0x51:case 0x52:case 0x53:case 0x54:case 0x55:
case 0x56:case 0x57:case 0x58:case 0x59:case 0x5a:case 0x5f:case 0x61:
case 0x62:case 0x63:case 0x64:case 0x65:case 0x66:case 0x67:case 0x68:
case 0x69:case 0x6a:case 0x6b:case 0x6c:case 0x6d:case 0x6e:case 0x6f:
case 0x70:case 0x71:case 0x72:case 0x73:case 0x74:case 0x75:case 0x76:
case 0x77:case 0x78:case 0x79:case 0x7a:
{
state.ptr += 1;
goto state_label_2; // identifier
}break;
}
}
end:;
block_copy_struct(state_ptr, &state);
return(result);
}
internal Token_List
lex_full_input_gas(Arena *arena, String_Const_u8 input){
Lex_State_Gas state = {};
lex_full_input_gas_init(&state, input);
Token_List list = {};
lex_full_input_gas_breaks(arena, &list, &state, max_u64);
return(list);
}
