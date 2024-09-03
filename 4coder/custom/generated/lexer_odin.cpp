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
u64 odin_main_keys_hash_array[343] = {
0x305023e5ecc549eb,0x0000000000000000,0x0000000000000000,0xe984e486c08656b5,
0x59e37ae37c093c9b,0x385a963af5d7c5d7,0x3d6992a6603c26bb,0xd35507898b5f50f7,
0x0000000000000000,0xd35507898b5ea827,0x0000000000000000,0xe984e136e00799cb,
0x0000000000000000,0xe984e49b33818379,0x0000000000000000,0xd9a8ca4c6982c61b,
0xfb990350601f0379,0xd9a8ca4c68290559,0x48712e33078e7b4d,0xd35507898b5cb1bf,
0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000,
0x0000000000000000,0xc181254fb01b0b15,0x59e37ae2ae740c89,0x2ed286433a938e19,
0x0000000000000000,0x59e37ae37f2dfdc3,0xd35507898b5ea189,0x543119b2a1833983,
0x0000000000000000,0x59e37afc0f253ef9,0x0000000000000000,0x0000000000000000,
0xd9a8ca4c6993c1fb,0xc181de1ecf16606b,0x0000000000000000,0x59e37ae344e97ac3,
0x0000000000000000,0x643d0b79363e6941,0x0000000000000000,0x0000000000000000,
0xdea1600065fad749,0x0000000000000000,0x5431199053ba9afd,0xd9a8ca4c6fe334db,
0x0000000000000000,0x0000000000000000,0x3491b1a4cfc1cc6b,0x0000000000000000,
0x7ecb85c2ce03bb27,0x59e37ae370ef5053,0x081a8c47b4f0586b,0x34f6ff7458574d41,
0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000,
0x59e37ae34451da3b,0x2162b41536e10749,0x0000000000000000,0xd9a8ca4c68292c63,
0x0000000000000000,0x0000000000000000,0xd35507898b5c79a9,0x0000000000000000,
0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000,
0xe984ecec10543bcb,0xd35507898b5cfe55,0x59e37ae2ae736943,0xc18131ccdc3fe7d9,
0x0000000000000000,0x0000000000000000,0xd9a8ca4c6996a9c1,0x0000000000000000,
0x0000000000000000,0xd35507898b5c0527,0x0000000000000000,0xd35507898b5ef627,
0x59e37ae370ef4f1b,0xa37c32bf36eb9f71,0x0000000000000000,0xd9a8ca4c6fe26555,
0xd35507898b5caf57,0x0000000000000000,0x0000000000000000,0x59e37ae37f34ae53,
0x2f6aed6533160feb,0x0000000000000000,0x0000000000000000,0x0000000000000000,
0x0000000000000000,0x59e37ae347211fc3,0x0000000000000000,0x59e37ae2adfbd74b,
0x446f521d5f54b423,0x0000000000000000,0x0000000000000000,0x0000000000000000,
0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000,
0x0000000000000000,0x0000000000000000,0xe984e2534d708735,0xd9a8ca4c698752cd,
0xd9a8ca4c69b67acd,0x0000000000000000,0x0000000000000000,0xe984e27bf8c95c41,
0x232ad5e44e48d7df,0xeebc8a1e441c68b7,0x52e42c25bde25b79,0x918301978ec25b79,
0x0000000000000000,0x0000000000000000,0x69d51174c9bc3a17,0xe984e480c5ab0963,
0x543119ad6b9aed99,0x0000000000000000,0x0000000000000000,0x543119976efebe5b,
0x0000000000000000,0x59e37afc0f30df23,0x2475deefd4dc5b79,0x0000000000000000,
0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000,
0x0000000000000000,0xc18158a7e3f03f3b,0xd9a8ca4c69eb509f,0xc7125fd30b616735,
0x0000000000000000,0xe984ecc657b670a3,0x543113a6081f0d27,0x0000000000000000,
0x0000000000000000,0x59e37ae37f34561b,0x0000000000000000,0x0000000000000000,
0x3e42a76c0fe52c6b,0xd9a8ca4c680eabc1,0x0000000000000000,0x0000000000000000,
0xd35507898b5c31a5,0x0000000000000000,0x0000000000000000,0xd35507898b5c5ddf,
0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000,
0xd35507898b5cfd55,0xd35507898b5ea8bf,0x5431199ebd2a034d,0x0000000000000000,
0xe985b0a254c7f0ff,0x39a0d8c98e03bb27,0xd9a8ca4c69e8cd9b,0x0000000000000000,
0xd35507898b5e9605,0x34f6ff7458565f37,0x0000000000000000,0x0000000000000000,
0xeebc8a1e441db68d,0x0000000000000000,0x0000000000000000,0x0000000000000000,
0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000,
0x0000000000000000,0x59e37ae37f2dfe5b,0x0000000000000000,0x0000000000000000,
0x0000000000000000,0x0000000000000000,0x5431199d0b9cda69,0xd35507898b5cbe77,
0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000,
0x144fc23d8e03bb27,0x0000000000000000,0x0000000000000000,0x59e37ae3718fef57,
0xd9a8ca4c682a5fbb,0xd9a8ca4c6984232b,0xd35507898b5c6769,0x2eb5262e4b31e837,
0x0000000000000000,0x54311997ebedf4bb,0x543113a60a56b37f,0x59e37ae2aa60c4cb,
0x0000000000000000,0x0000000000000000,0x0000000000000000,0x543119626de4de5b,
0xd9a8ca4c698096cd,0x5431199064120379,0x69d51174c9bc3a6f,0x0000000000000000,
0x0000000000000000,0x0000000000000000,0x0000000000000000,0xd9a8ca4c6982dc53,
0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000,
0x4e1521e1335dbb79,0x0000000000000000,0x0000000000000000,0xd35507898b5e9cef,
0xd35507898b5c045f,0xc4fa39f4ce03bb27,0xd9a8ca4c680f87cb,0x0000000000000000,
0x0000000000000000,0x0000000000000000,0x0000000000000000,0xe984e486ce5868b1,
0x0000000000000000,0x0000000000000000,0xd9a8ca4c6829078b,0xd35507898b5ef6bf,
0xd9a8ca4c6f1d70e9,0xe747b861202bf927,0x0000000000000000,0x59e37ae344e9661b,
0x0000000000000000,0x0000000000000000,0xfdef55fb0ab58483,0xd35507898b5cb149,
0x0000000000000000,0x0000000000000000,0x59e37ae37c090143,0x0000000000000000,
0x0000000000000000,0xd9a8ca4c68290799,0x0dd2aaa5a21cd749,0x2ed006420a8fe4ad,
0x0000000000000000,0x0000000000000000,0x543113a60823da3b,0x59e37ae2a8b873d9,
0x2f6b993d5b08dcfb,0x0000000000000000,0x0000000000000000,0x0000000000000000,
0x0000000000000000,0x0000000000000000,0x6b1f269398d73c83,0x0000000000000000,
0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000,
0x6d8dd38566ced749,0x5431199e81ce23d7,0xbb7ba56398deae53,0xd9a8ca4c68129113,
0x0000000000000000,0x0000000000000000,0x0000000000000000,0x543119906412c759,
0x3491fb9053ce69cd,0xd35507898b5ef6e9,0x0000000000000000,0x0000000000000000,
0xc18dc3160b764941,0x543119626de42063,0xd9a8ca4c68292be7,0x0000000000000000,
0xe9858bf0c2f390db,0xd9a8ca4c69e8ce13,0x0000000000000000,0x0000000000000000,
0x0000000000000000,0x2f6a6c7145325ca3,0xd9a8ca4c6812c161,0x0000000000000000,
0x0000000000000000,0x0000000000000000,0xd9a8ca4c680fede3,0x0000000000000000,
0xd35507898b5ca2c1,0x0000000000000000,0x0000000000000000,0x0000000000000000,
0x69d51174c9bc3ac9,0x2e01015c5d179083,0x0000000000000000,0x69d51174c9bc442d,
0xd35507898b5f4f71,0xd35507898b5ca2c9,0x3055a0a4225a81db,0x643d0b793638b1d7,
0x0000000000000000,0xcdd8453d97bc26bb,0x47e7036ef12a9e6b,0xd9a8ca4c6996c6cd,
0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000,
0xa0138731f383bb27,0x0000000000000000,0x0000000000000000,0x0000000000000000,
0x0000000000000000,0x0000000000000000,0x2edbba8f95791083,0x0000000000000000,
0x543119976efeb063,0x0000000000000000,0x0000000000000000,0x0000000000000000,
0x0000000000000000,0x0000000000000000,0x69d51174c9bc4449,0xd9a8ca4c69e34609,
0x69d51174c9bc3991,0x2eb5262e4b31c089,0xd9a8ca4c69eff1cd,0x0000000000000000,
0x59e37ae347211f5b,0x0000000000000000,0xe984ecc4ea65a06b,0x0000000000000000,
0x0000000000000000,0x0000000000000000,0x0000000000000000,
};
u8 odin_main_keys_key_array_0[] = {0x6f,0x66,0x66,0x73,0x65,0x74,0x5f,0x6f,0x66,};
u8 odin_main_keys_key_array_3[] = {0x63,0x6f,0x6e,0x74,0x65,0x78,0x74,};
u8 odin_main_keys_key_array_4[] = {0x69,0x33,0x32,0x62,0x65,};
u8 odin_main_keys_key_array_5[] = {0x61,0x70,0x70,0x65,0x6e,0x64,0x5f,0x73,0x6f,0x61,};
u8 odin_main_keys_key_array_6[] = {0x6f,0x72,0x64,0x65,0x72,0x65,0x64,0x5f,0x72,0x65,0x6d,0x6f,0x76,0x65,};
u8 odin_main_keys_key_array_7[] = {0x66,0x6f,0x72,};
u8 odin_main_keys_key_array_9[] = {0x66,0x33,0x32,};
u8 odin_main_keys_key_array_11[] = {0x74,0x79,0x70,0x65,0x5f,0x6f,0x66,};
u8 odin_main_keys_key_array_13[] = {0x63,0x73,0x74,0x72,0x69,0x6e,0x67,};
u8 odin_main_keys_key_array_15[] = {0x69,0x38,0x62,0x65,};
u8 odin_main_keys_key_array_16[] = {0x61,0x70,0x70,0x65,0x6e,0x64,0x5f,0x73,0x74,0x72,0x69,0x6e,0x67,};
u8 odin_main_keys_key_array_17[] = {0x63,0x61,0x72,0x64,};
u8 odin_main_keys_key_array_18[] = {0x66,0x61,0x6c,0x6c,0x74,0x68,0x72,0x6f,0x75,0x67,0x68,};
u8 odin_main_keys_key_array_19[] = {0x69,0x31,0x36,};
u8 odin_main_keys_key_array_25[] = {0x66,0x72,0x65,0x65,0x5f,0x61,0x6c,0x6c,};
u8 odin_main_keys_key_array_26[] = {0x63,0x6c,0x61,0x6d,0x70,};
u8 odin_main_keys_key_array_27[] = {0x61,0x75,0x74,0x6f,0x5f,0x63,0x61,0x73,0x74,};
u8 odin_main_keys_key_array_29[] = {0x69,0x31,0x36,0x6c,0x65,};
u8 odin_main_keys_key_array_30[] = {0x66,0x36,0x34,};
u8 odin_main_keys_key_array_31[] = {0x64,0x65,0x6c,0x65,0x74,0x65,};
u8 odin_main_keys_key_array_33[] = {0x75,0x73,0x69,0x6e,0x67,};
u8 odin_main_keys_key_array_36[] = {0x74,0x72,0x75,0x65,};
u8 odin_main_keys_key_array_37[] = {0x61,0x6c,0x69,0x67,0x6e,0x5f,0x6f,0x66,};
u8 odin_main_keys_key_array_39[] = {0x75,0x33,0x32,0x6c,0x65,};
u8 odin_main_keys_key_array_41[] = {0x72,0x65,0x73,0x65,0x72,0x76,0x65,0x5f,0x6d,0x61,0x70,};
u8 odin_main_keys_key_array_44[] = {0x65,0x78,0x63,0x6c,0x5f,0x65,0x6c,0x65,0x6d,0x73,};
u8 odin_main_keys_key_array_46[] = {0x73,0x77,0x69,0x74,0x63,0x68,};
u8 odin_main_keys_key_array_47[] = {0x72,0x75,0x6e,0x65,};
u8 odin_main_keys_key_array_50[] = {0x63,0x6f,0x70,0x79,0x5f,0x73,0x6c,0x69,0x63,0x65,};
u8 odin_main_keys_key_array_52[] = {0x6d,0x61,0x6b,0x65,0x5f,0x64,0x79,0x6e,0x61,0x6d,0x69,0x63,0x5f,0x61,0x72,0x72,0x61,0x79,};
u8 odin_main_keys_key_array_53[] = {0x75,0x36,0x34,0x6c,0x65,};
u8 odin_main_keys_key_array_54[] = {0x6d,0x61,0x6b,0x65,0x5f,0x73,0x6c,0x69,0x63,0x65,};
u8 odin_main_keys_key_array_55[] = {0x64,0x65,0x6c,0x65,0x74,0x65,0x5f,0x6d,0x61,0x70,};
u8 odin_main_keys_key_array_60[] = {0x77,0x68,0x65,0x72,0x65,};
u8 odin_main_keys_key_array_61[] = {0x61,0x70,0x70,0x65,0x6e,0x64,0x5f,0x73,0x6f,0x61,0x5f,0x65,0x6c,0x65,0x6d,0x73,};
u8 odin_main_keys_key_array_63[] = {0x63,0x6f,0x6e,0x6a,};
u8 odin_main_keys_key_array_66[] = {0x75,0x36,0x34,};
u8 odin_main_keys_key_array_72[] = {0x73,0x69,0x7a,0x65,0x5f,0x6f,0x66,};
u8 odin_main_keys_key_array_73[] = {0x6e,0x65,0x77,};
u8 odin_main_keys_key_array_74[] = {0x63,0x6c,0x65,0x61,0x72,};
u8 odin_main_keys_key_array_75[] = {0x64,0x69,0x73,0x74,0x69,0x6e,0x63,0x74,};
u8 odin_main_keys_key_array_78[] = {0x69,0x6e,0x63,0x6c,};
u8 odin_main_keys_key_array_81[] = {0x75,0x33,0x32,};
u8 odin_main_keys_key_array_83[] = {0x62,0x33,0x32,};
u8 odin_main_keys_key_array_84[] = {0x75,0x36,0x34,0x62,0x65,};
u8 odin_main_keys_key_array_85[] = {0x6d,0x61,0x6b,0x65,0x5f,0x64,0x79,0x6e,0x61,0x6d,0x69,0x63,0x5f,0x61,0x72,0x72,0x61,0x79,0x5f,0x6c,0x65,0x6e,0x5f,0x63,0x61,0x70,};
u8 odin_main_keys_key_array_87[] = {0x72,0x65,0x61,0x6c,};
u8 odin_main_keys_key_array_88[] = {0x6d,0x69,0x6e,};
u8 odin_main_keys_key_array_91[] = {0x69,0x36,0x34,0x6c,0x65,};
u8 odin_main_keys_key_array_92[] = {0x74,0x79,0x70,0x65,0x69,0x64,0x5f,0x6f,0x66,};
u8 odin_main_keys_key_array_97[] = {0x75,0x31,0x36,0x6c,0x65,};
u8 odin_main_keys_key_array_99[] = {0x66,0x61,0x6c,0x73,0x65,};
u8 odin_main_keys_key_array_100[] = {0x71,0x75,0x61,0x74,0x65,0x72,0x6e,0x69,0x6f,0x6e,};
u8 odin_main_keys_key_array_110[] = {0x62,0x69,0x74,0x5f,0x73,0x65,0x74,};
u8 odin_main_keys_key_array_111[] = {0x69,0x31,0x32,0x38,};
u8 odin_main_keys_key_array_112[] = {0x6b,0x6d,0x61,0x67,};
u8 odin_main_keys_key_array_115[] = {0x64,0x79,0x6e,0x61,0x6d,0x69,0x63,};
u8 odin_main_keys_key_array_116[] = {0x6d,0x61,0x6b,0x65,0x5f,0x64,0x79,0x6e,0x61,0x6d,0x69,0x63,0x5f,0x61,0x72,0x72,0x61,0x79,0x5f,0x6c,0x65,0x6e,};
u8 odin_main_keys_key_array_117[] = {0x71,0x75,0x61,0x74,0x65,0x72,0x6e,0x69,0x6f,0x6e,0x32,0x35,0x36,};
u8 odin_main_keys_key_array_118[] = {0x61,0x70,0x70,0x65,0x6e,0x64,0x5f,0x65,0x6c,0x65,0x6d,0x5f,0x73,0x74,0x72,0x69,0x6e,0x67,};
u8 odin_main_keys_key_array_119[] = {0x64,0x65,0x6c,0x65,0x74,0x65,0x5f,0x73,0x74,0x72,0x69,0x6e,0x67,};
u8 odin_main_keys_key_array_122[] = {0x69,0x6e,};
u8 odin_main_keys_key_array_123[] = {0x66,0x6f,0x72,0x65,0x69,0x67,0x6e,};
u8 odin_main_keys_key_array_124[] = {0x61,0x70,0x70,0x65,0x6e,0x64,};
u8 odin_main_keys_key_array_127[] = {0x75,0x31,0x32,0x38,0x62,0x65,};
u8 odin_main_keys_key_array_129[] = {0x75,0x6e,0x69,0x6f,0x6e,};
u8 odin_main_keys_key_array_130[] = {0x63,0x6f,0x70,0x79,0x5f,0x66,0x72,0x6f,0x6d,0x5f,0x73,0x74,0x72,0x69,0x6e,0x67,};
u8 odin_main_keys_key_array_137[] = {0x63,0x6f,0x6e,0x74,0x69,0x6e,0x75,0x65,};
u8 odin_main_keys_key_array_138[] = {0x77,0x68,0x65,0x6e,};
u8 odin_main_keys_key_array_139[] = {0x65,0x78,0x63,0x6c,0x5f,0x62,0x69,0x74,0x5f,0x73,0x65,0x74,};
u8 odin_main_keys_key_array_141[] = {0x73,0x77,0x69,0x7a,0x7a,0x6c,0x65,};
u8 odin_main_keys_key_array_142[] = {0x72,0x65,0x74,0x75,0x72,0x6e,};
u8 odin_main_keys_key_array_145[] = {0x69,0x36,0x34,0x62,0x65,};
u8 odin_main_keys_key_array_148[] = {0x64,0x65,0x6c,0x65,0x74,0x65,0x5f,0x73,0x6c,0x69,0x63,0x65,};
u8 odin_main_keys_key_array_149[] = {0x65,0x78,0x63,0x6c,};
u8 odin_main_keys_key_array_152[] = {0x70,0x6f,0x70,};
u8 odin_main_keys_key_array_155[] = {0x6c,0x65,0x6e,};
u8 odin_main_keys_key_array_160[] = {0x6e,0x69,0x6c,};
u8 odin_main_keys_key_array_161[] = {0x66,0x31,0x36,};
u8 odin_main_keys_key_array_162[] = {0x74,0x79,0x70,0x65,0x69,0x64,};
u8 odin_main_keys_key_array_164[] = {0x75,0x69,0x6e,0x74,0x70,0x74,0x72,};
u8 odin_main_keys_key_array_165[] = {0x72,0x65,0x73,0x69,0x7a,0x65,0x5f,0x64,0x79,0x6e,0x61,0x6d,0x69,0x63,0x5f,0x61,0x72,0x72,0x61,0x79,};
u8 odin_main_keys_key_array_166[] = {0x75,0x38,0x62,0x65,};
u8 odin_main_keys_key_array_168[] = {0x61,0x62,0x73,};
u8 odin_main_keys_key_array_169[] = {0x64,0x65,0x6c,0x65,0x74,0x65,0x5f,0x6b,0x65,0x79,};
u8 odin_main_keys_key_array_172[] = {0x71,0x75,0x61,0x74,0x65,0x72,0x6e,0x69,0x6f,0x6e,0x31,0x32,0x38,};
u8 odin_main_keys_key_array_181[] = {0x69,0x31,0x36,0x62,0x65,};
u8 odin_main_keys_key_array_186[] = {0x69,0x6d,0x70,0x6f,0x72,0x74,};
u8 odin_main_keys_key_array_187[] = {0x69,0x33,0x32,};
u8 odin_main_keys_key_array_192[] = {0x63,0x6c,0x65,0x61,0x72,0x5f,0x64,0x79,0x6e,0x61,0x6d,0x69,0x63,0x5f,0x61,0x72,0x72,0x61,0x79,};
u8 odin_main_keys_key_array_195[] = {0x6e,0x6f,0x74,0x69,0x6e,};
u8 odin_main_keys_key_array_196[] = {0x66,0x72,0x65,0x65,};
u8 odin_main_keys_key_array_197[] = {0x6d,0x61,0x6b,0x65,};
u8 odin_main_keys_key_array_198[] = {0x69,0x6e,0x74,};
u8 odin_main_keys_key_array_199[] = {0x63,0x6f,0x6d,0x70,0x6c,0x65,0x78,0x33,0x32,};
u8 odin_main_keys_key_array_201[] = {0x6f,0x70,0x61,0x71,0x75,0x65,};
u8 odin_main_keys_key_array_202[] = {0x72,0x61,0x77,0x70,0x74,0x72,};
u8 odin_main_keys_key_array_203[] = {0x64,0x65,0x66,0x65,0x72,};
u8 odin_main_keys_key_array_207[] = {0x69,0x31,0x32,0x38,0x62,0x65,};
u8 odin_main_keys_key_array_208[] = {0x6a,0x6d,0x61,0x67,};
u8 odin_main_keys_key_array_209[] = {0x73,0x74,0x72,0x69,0x6e,0x67,};
u8 odin_main_keys_key_array_210[] = {0x69,0x66,};
u8 odin_main_keys_key_array_215[] = {0x69,0x38,0x6c,0x65,};
u8 odin_main_keys_key_array_220[] = {0x64,0x65,0x6c,0x65,0x74,0x65,0x5f,0x63,0x73,0x74,0x72,0x69,0x6e,0x67,};
u8 odin_main_keys_key_array_223[] = {0x61,0x6e,0x79,};
u8 odin_main_keys_key_array_224[] = {0x75,0x31,0x36,};
u8 odin_main_keys_key_array_225[] = {0x72,0x65,0x73,0x65,0x72,0x76,0x65,0x5f,0x64,0x79,0x6e,0x61,0x6d,0x69,0x63,0x5f,0x61,0x72,0x72,0x61,0x79,};
u8 odin_main_keys_key_array_226[] = {0x65,0x6c,0x73,0x65,};
u8 odin_main_keys_key_array_231[] = {0x63,0x6f,0x6d,0x70,0x6c,0x65,0x78,};
u8 odin_main_keys_key_array_234[] = {0x63,0x61,0x73,0x65,};
u8 odin_main_keys_key_array_235[] = {0x62,0x31,0x36,};
u8 odin_main_keys_key_array_236[] = {0x75,0x69,0x6e,0x74,};
u8 odin_main_keys_key_array_237[] = {0x69,0x6e,0x69,0x74,0x5f,0x67,0x6c,0x6f,0x62,0x61,0x6c,0x5f,0x74,0x65,0x6d,0x70,0x6f,0x72,0x61,0x72,0x79,0x5f,0x61,0x6c,0x6c,0x6f,0x63,0x61,0x74,0x6f,0x72,};
u8 odin_main_keys_key_array_239[] = {0x75,0x33,0x32,0x62,0x65,};
u8 odin_main_keys_key_array_242[] = {0x61,0x70,0x70,0x65,0x6e,0x64,0x5f,0x73,0x6f,0x61,0x5f,0x65,0x6c,0x65,0x6d,};
u8 odin_main_keys_key_array_243[] = {0x69,0x36,0x34,};
u8 odin_main_keys_key_array_246[] = {0x69,0x33,0x32,0x6c,0x65,};
u8 odin_main_keys_key_array_249[] = {0x63,0x61,0x73,0x74,};
u8 odin_main_keys_key_array_250[] = {0x69,0x6e,0x63,0x6c,0x5f,0x65,0x6c,0x65,0x6d,0x73,};
u8 odin_main_keys_key_array_251[] = {0x62,0x69,0x74,0x5f,0x66,0x69,0x65,0x6c,0x64,};
u8 odin_main_keys_key_array_254[] = {0x72,0x65,0x73,0x69,0x7a,0x65,};
u8 odin_main_keys_key_array_255[] = {0x62,0x72,0x65,0x61,0x6b,};
u8 odin_main_keys_key_array_256[] = {0x6e,0x6f,0x5f,0x69,0x6e,0x6c,0x69,0x6e,0x65,};
u8 odin_main_keys_key_array_262[] = {0x61,0x70,0x70,0x65,0x6e,0x64,0x5f,0x65,0x6c,0x65,0x6d,};
u8 odin_main_keys_key_array_268[] = {0x61,0x70,0x70,0x65,0x6e,0x64,0x5f,0x65,0x6c,0x65,0x6d,0x73,};
u8 odin_main_keys_key_array_269[] = {0x6e,0x6f,0x74,0x5f,0x69,0x6e,};
u8 odin_main_keys_key_array_270[] = {0x65,0x78,0x70,0x61,0x6e,0x64,0x5f,0x74,0x6f,0x5f,0x74,0x75,0x70,0x6c,0x65,};
u8 odin_main_keys_key_array_271[] = {0x62,0x79,0x74,0x65,};
u8 odin_main_keys_key_array_275[] = {0x73,0x74,0x72,0x75,0x63,0x74,};
u8 odin_main_keys_key_array_276[] = {0x63,0x6f,0x6d,0x70,0x6c,0x65,0x78,0x31,0x32,0x38,};
u8 odin_main_keys_key_array_277[] = {0x62,0x36,0x34,};
u8 odin_main_keys_key_array_280[] = {0x6d,0x61,0x6b,0x65,0x5f,0x6d,0x61,0x70,};
u8 odin_main_keys_key_array_281[] = {0x69,0x31,0x32,0x38,0x6c,0x65,};
u8 odin_main_keys_key_array_282[] = {0x63,0x6f,0x70,0x79,};
u8 odin_main_keys_key_array_284[] = {0x72,0x65,0x73,0x65,0x72,0x76,0x65,};
u8 odin_main_keys_key_array_285[] = {0x75,0x38,0x6c,0x65,};
u8 odin_main_keys_key_array_289[] = {0x74,0x72,0x61,0x6e,0x73,0x6d,0x75,0x74,0x65,};
u8 odin_main_keys_key_array_290[] = {0x62,0x6f,0x6f,0x6c,};
u8 odin_main_keys_key_array_294[] = {0x65,0x6e,0x75,0x6d,};
u8 odin_main_keys_key_array_296[] = {0x6d,0x61,0x70,};
u8 odin_main_keys_key_array_300[] = {0x69,0x38,};
u8 odin_main_keys_key_array_301[] = {0x65,0x78,0x63,0x6c,0x5f,0x65,0x6c,0x65,0x6d,};
u8 odin_main_keys_key_array_303[] = {0x62,0x38,};
u8 odin_main_keys_key_array_304[] = {0x63,0x61,0x70,};
u8 odin_main_keys_key_array_305[] = {0x6d,0x61,0x78,};
u8 odin_main_keys_key_array_306[] = {0x6e,0x65,0x77,0x5f,0x63,0x6c,0x6f,0x6e,0x65,};
u8 odin_main_keys_key_array_307[] = {0x72,0x65,0x73,0x65,0x72,0x76,0x65,0x5f,0x73,0x6f,0x61,};
u8 odin_main_keys_key_array_309[] = {0x75,0x6e,0x6f,0x72,0x65,0x64,0x65,0x72,0x65,0x64,0x5f,0x72,0x65,0x6d,0x6f,0x76,0x65,};
u8 odin_main_keys_key_array_310[] = {0x74,0x79,0x70,0x65,0x5f,0x69,0x6e,0x66,0x6f,0x5f,0x6f,0x66,};
u8 odin_main_keys_key_array_311[] = {0x69,0x6d,0x61,0x67,};
u8 odin_main_keys_key_array_316[] = {0x64,0x65,0x6c,0x65,0x74,0x65,0x5f,0x64,0x79,0x6e,0x61,0x6d,0x69,0x63,0x5f,0x61,0x72,0x72,0x61,0x79,};
u8 odin_main_keys_key_array_322[] = {0x69,0x6e,0x63,0x6c,0x5f,0x65,0x6c,0x65,0x6d,};
u8 odin_main_keys_key_array_324[] = {0x75,0x31,0x32,0x38,0x6c,0x65,};
u8 odin_main_keys_key_array_330[] = {0x64,0x6f,};
u8 odin_main_keys_key_array_331[] = {0x70,0x72,0x6f,0x63,};
u8 odin_main_keys_key_array_332[] = {0x75,0x38,};
u8 odin_main_keys_key_array_333[] = {0x63,0x6f,0x6d,0x70,0x6c,0x65,0x78,0x36,0x34,};
u8 odin_main_keys_key_array_334[] = {0x75,0x31,0x32,0x38,};
u8 odin_main_keys_key_array_336[] = {0x75,0x31,0x36,0x62,0x65,};
u8 odin_main_keys_key_array_338[] = {0x70,0x61,0x63,0x6b,0x61,0x67,0x65,};
String_Const_u8 odin_main_keys_key_array[343] = {
{odin_main_keys_key_array_0, 9},
{0, 0},
{0, 0},
{odin_main_keys_key_array_3, 7},
{odin_main_keys_key_array_4, 5},
{odin_main_keys_key_array_5, 10},
{odin_main_keys_key_array_6, 14},
{odin_main_keys_key_array_7, 3},
{0, 0},
{odin_main_keys_key_array_9, 3},
{0, 0},
{odin_main_keys_key_array_11, 7},
{0, 0},
{odin_main_keys_key_array_13, 7},
{0, 0},
{odin_main_keys_key_array_15, 4},
{odin_main_keys_key_array_16, 13},
{odin_main_keys_key_array_17, 4},
{odin_main_keys_key_array_18, 11},
{odin_main_keys_key_array_19, 3},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{odin_main_keys_key_array_25, 8},
{odin_main_keys_key_array_26, 5},
{odin_main_keys_key_array_27, 9},
{0, 0},
{odin_main_keys_key_array_29, 5},
{odin_main_keys_key_array_30, 3},
{odin_main_keys_key_array_31, 6},
{0, 0},
{odin_main_keys_key_array_33, 5},
{0, 0},
{0, 0},
{odin_main_keys_key_array_36, 4},
{odin_main_keys_key_array_37, 8},
{0, 0},
{odin_main_keys_key_array_39, 5},
{0, 0},
{odin_main_keys_key_array_41, 11},
{0, 0},
{0, 0},
{odin_main_keys_key_array_44, 10},
{0, 0},
{odin_main_keys_key_array_46, 6},
{odin_main_keys_key_array_47, 4},
{0, 0},
{0, 0},
{odin_main_keys_key_array_50, 10},
{0, 0},
{odin_main_keys_key_array_52, 18},
{odin_main_keys_key_array_53, 5},
{odin_main_keys_key_array_54, 10},
{odin_main_keys_key_array_55, 10},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{odin_main_keys_key_array_60, 5},
{odin_main_keys_key_array_61, 16},
{0, 0},
{odin_main_keys_key_array_63, 4},
{0, 0},
{0, 0},
{odin_main_keys_key_array_66, 3},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{odin_main_keys_key_array_72, 7},
{odin_main_keys_key_array_73, 3},
{odin_main_keys_key_array_74, 5},
{odin_main_keys_key_array_75, 8},
{0, 0},
{0, 0},
{odin_main_keys_key_array_78, 4},
{0, 0},
{0, 0},
{odin_main_keys_key_array_81, 3},
{0, 0},
{odin_main_keys_key_array_83, 3},
{odin_main_keys_key_array_84, 5},
{odin_main_keys_key_array_85, 26},
{0, 0},
{odin_main_keys_key_array_87, 4},
{odin_main_keys_key_array_88, 3},
{0, 0},
{0, 0},
{odin_main_keys_key_array_91, 5},
{odin_main_keys_key_array_92, 9},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{odin_main_keys_key_array_97, 5},
{0, 0},
{odin_main_keys_key_array_99, 5},
{odin_main_keys_key_array_100, 10},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{odin_main_keys_key_array_110, 7},
{odin_main_keys_key_array_111, 4},
{odin_main_keys_key_array_112, 4},
{0, 0},
{0, 0},
{odin_main_keys_key_array_115, 7},
{odin_main_keys_key_array_116, 22},
{odin_main_keys_key_array_117, 13},
{odin_main_keys_key_array_118, 18},
{odin_main_keys_key_array_119, 13},
{0, 0},
{0, 0},
{odin_main_keys_key_array_122, 2},
{odin_main_keys_key_array_123, 7},
{odin_main_keys_key_array_124, 6},
{0, 0},
{0, 0},
{odin_main_keys_key_array_127, 6},
{0, 0},
{odin_main_keys_key_array_129, 5},
{odin_main_keys_key_array_130, 16},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{odin_main_keys_key_array_137, 8},
{odin_main_keys_key_array_138, 4},
{odin_main_keys_key_array_139, 12},
{0, 0},
{odin_main_keys_key_array_141, 7},
{odin_main_keys_key_array_142, 6},
{0, 0},
{0, 0},
{odin_main_keys_key_array_145, 5},
{0, 0},
{0, 0},
{odin_main_keys_key_array_148, 12},
{odin_main_keys_key_array_149, 4},
{0, 0},
{0, 0},
{odin_main_keys_key_array_152, 3},
{0, 0},
{0, 0},
{odin_main_keys_key_array_155, 3},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{odin_main_keys_key_array_160, 3},
{odin_main_keys_key_array_161, 3},
{odin_main_keys_key_array_162, 6},
{0, 0},
{odin_main_keys_key_array_164, 7},
{odin_main_keys_key_array_165, 20},
{odin_main_keys_key_array_166, 4},
{0, 0},
{odin_main_keys_key_array_168, 3},
{odin_main_keys_key_array_169, 10},
{0, 0},
{0, 0},
{odin_main_keys_key_array_172, 13},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{odin_main_keys_key_array_181, 5},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{odin_main_keys_key_array_186, 6},
{odin_main_keys_key_array_187, 3},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{odin_main_keys_key_array_192, 19},
{0, 0},
{0, 0},
{odin_main_keys_key_array_195, 5},
{odin_main_keys_key_array_196, 4},
{odin_main_keys_key_array_197, 4},
{odin_main_keys_key_array_198, 3},
{odin_main_keys_key_array_199, 9},
{0, 0},
{odin_main_keys_key_array_201, 6},
{odin_main_keys_key_array_202, 6},
{odin_main_keys_key_array_203, 5},
{0, 0},
{0, 0},
{0, 0},
{odin_main_keys_key_array_207, 6},
{odin_main_keys_key_array_208, 4},
{odin_main_keys_key_array_209, 6},
{odin_main_keys_key_array_210, 2},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{odin_main_keys_key_array_215, 4},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{odin_main_keys_key_array_220, 14},
{0, 0},
{0, 0},
{odin_main_keys_key_array_223, 3},
{odin_main_keys_key_array_224, 3},
{odin_main_keys_key_array_225, 21},
{odin_main_keys_key_array_226, 4},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{odin_main_keys_key_array_231, 7},
{0, 0},
{0, 0},
{odin_main_keys_key_array_234, 4},
{odin_main_keys_key_array_235, 3},
{odin_main_keys_key_array_236, 4},
{odin_main_keys_key_array_237, 31},
{0, 0},
{odin_main_keys_key_array_239, 5},
{0, 0},
{0, 0},
{odin_main_keys_key_array_242, 15},
{odin_main_keys_key_array_243, 3},
{0, 0},
{0, 0},
{odin_main_keys_key_array_246, 5},
{0, 0},
{0, 0},
{odin_main_keys_key_array_249, 4},
{odin_main_keys_key_array_250, 10},
{odin_main_keys_key_array_251, 9},
{0, 0},
{0, 0},
{odin_main_keys_key_array_254, 6},
{odin_main_keys_key_array_255, 5},
{odin_main_keys_key_array_256, 9},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{odin_main_keys_key_array_262, 11},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{odin_main_keys_key_array_268, 12},
{odin_main_keys_key_array_269, 6},
{odin_main_keys_key_array_270, 15},
{odin_main_keys_key_array_271, 4},
{0, 0},
{0, 0},
{0, 0},
{odin_main_keys_key_array_275, 6},
{odin_main_keys_key_array_276, 10},
{odin_main_keys_key_array_277, 3},
{0, 0},
{0, 0},
{odin_main_keys_key_array_280, 8},
{odin_main_keys_key_array_281, 6},
{odin_main_keys_key_array_282, 4},
{0, 0},
{odin_main_keys_key_array_284, 7},
{odin_main_keys_key_array_285, 4},
{0, 0},
{0, 0},
{0, 0},
{odin_main_keys_key_array_289, 9},
{odin_main_keys_key_array_290, 4},
{0, 0},
{0, 0},
{0, 0},
{odin_main_keys_key_array_294, 4},
{0, 0},
{odin_main_keys_key_array_296, 3},
{0, 0},
{0, 0},
{0, 0},
{odin_main_keys_key_array_300, 2},
{odin_main_keys_key_array_301, 9},
{0, 0},
{odin_main_keys_key_array_303, 2},
{odin_main_keys_key_array_304, 3},
{odin_main_keys_key_array_305, 3},
{odin_main_keys_key_array_306, 9},
{odin_main_keys_key_array_307, 11},
{0, 0},
{odin_main_keys_key_array_309, 17},
{odin_main_keys_key_array_310, 12},
{odin_main_keys_key_array_311, 4},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{odin_main_keys_key_array_316, 20},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{odin_main_keys_key_array_322, 9},
{0, 0},
{odin_main_keys_key_array_324, 6},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{odin_main_keys_key_array_330, 2},
{odin_main_keys_key_array_331, 4},
{odin_main_keys_key_array_332, 2},
{odin_main_keys_key_array_333, 9},
{odin_main_keys_key_array_334, 4},
{0, 0},
{odin_main_keys_key_array_336, 5},
{0, 0},
{odin_main_keys_key_array_338, 7},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
};
Lexeme_Table_Value odin_main_keys_value_array[343] = {
{4, TokenOdinKind_offset_of},
{0, 0},
{0, 0},
{4, TokenOdinKind_context},
{4, TokenOdinKind_i32be},
{4, TokenOdinKind_append_soa},
{4, TokenOdinKind_ordered_remove},
{4, TokenOdinKind_for},
{0, 0},
{4, TokenOdinKind_f32},
{0, 0},
{4, TokenOdinKind_type_of},
{0, 0},
{4, TokenOdinKind_cstring},
{0, 0},
{4, TokenOdinKind_i8be},
{4, TokenOdinKind_append_string},
{4, TokenOdinKind_card},
{4, TokenOdinKind_fallthrough},
{4, TokenOdinKind_i16},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{4, TokenOdinKind_free_all},
{4, TokenOdinKind_clamp},
{4, TokenOdinKind_auto_cast},
{0, 0},
{4, TokenOdinKind_i16le},
{4, TokenOdinKind_f64},
{4, TokenOdinKind_delete},
{0, 0},
{4, TokenOdinKind_using},
{0, 0},
{0, 0},
{8, TokenOdinKind_LiteralTrue},
{4, TokenOdinKind_align_of},
{0, 0},
{4, TokenOdinKind_u32le},
{0, 0},
{4, TokenOdinKind_reserve_map},
{0, 0},
{0, 0},
{4, TokenOdinKind_excl_elems},
{0, 0},
{4, TokenOdinKind_switch},
{4, TokenOdinKind_rune},
{0, 0},
{0, 0},
{4, TokenOdinKind_copy_slice},
{0, 0},
{4, TokenOdinKind_make_dynamic_array},
{4, TokenOdinKind_u64le},
{4, TokenOdinKind_make_slice},
{4, TokenOdinKind_delete_map},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{4, TokenOdinKind_where},
{4, TokenOdinKind_append_soa_elems},
{0, 0},
{4, TokenOdinKind_conj},
{0, 0},
{0, 0},
{4, TokenOdinKind_u64},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{4, TokenOdinKind_size_of},
{4, TokenOdinKind_new},
{4, TokenOdinKind_clear},
{4, TokenOdinKind_distinct},
{0, 0},
{0, 0},
{4, TokenOdinKind_incl},
{0, 0},
{0, 0},
{4, TokenOdinKind_u32},
{0, 0},
{4, TokenOdinKind_b32},
{4, TokenOdinKind_u64be},
{4, TokenOdinKind_make_dynamic_array_len_cap},
{0, 0},
{4, TokenOdinKind_real},
{4, TokenOdinKind_min},
{0, 0},
{0, 0},
{4, TokenOdinKind_i64le},
{4, TokenOdinKind_typeid_of},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{4, TokenOdinKind_u16le},
{0, 0},
{8, TokenOdinKind_LiteralFalse},
{4, TokenOdinKind_quaternion},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{4, TokenOdinKind_bit_set},
{4, TokenOdinKind_i128},
{4, TokenOdinKind_kmag},
{0, 0},
{0, 0},
{4, TokenOdinKind_dynamic},
{4, TokenOdinKind_make_dynamic_array_len},
{4, TokenOdinKind_quaternion256},
{4, TokenOdinKind_append_elem_string},
{4, TokenOdinKind_delete_string},
{0, 0},
{0, 0},
{4, TokenOdinKind_in},
{4, TokenOdinKind_foreign},
{4, TokenOdinKind_append},
{0, 0},
{0, 0},
{4, TokenOdinKind_u128be},
{0, 0},
{4, TokenOdinKind_union},
{4, TokenOdinKind_copy_from_string},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{4, TokenOdinKind_continue},
{4, TokenOdinKind_when},
{4, TokenOdinKind_excl_bit_set},
{0, 0},
{4, TokenOdinKind_swizzle},
{4, TokenOdinKind_return},
{0, 0},
{0, 0},
{4, TokenOdinKind_i64be},
{0, 0},
{0, 0},
{4, TokenOdinKind_delete_slice},
{4, TokenOdinKind_excl},
{0, 0},
{0, 0},
{4, TokenOdinKind_pop},
{0, 0},
{0, 0},
{4, TokenOdinKind_len},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{8, TokenOdinKind_LiteralNil},
{4, TokenOdinKind_f16},
{4, TokenOdinKind_typeid},
{0, 0},
{4, TokenOdinKind_uintptr},
{4, TokenOdinKind_resize_dynamic_array},
{4, TokenOdinKind_u8be},
{0, 0},
{4, TokenOdinKind_abs},
{4, TokenOdinKind_delete_key},
{0, 0},
{0, 0},
{4, TokenOdinKind_quaternion128},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{4, TokenOdinKind_i16be},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{4, TokenOdinKind_import},
{4, TokenOdinKind_i32},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{4, TokenOdinKind_clear_dynamic_array},
{0, 0},
{0, 0},
{4, TokenOdinKind_notin},
{4, TokenOdinKind_free},
{4, TokenOdinKind_make},
{4, TokenOdinKind_int},
{4, TokenOdinKind_complex32},
{0, 0},
{4, TokenOdinKind_opaque},
{4, TokenOdinKind_rawptr},
{4, TokenOdinKind_defer},
{0, 0},
{0, 0},
{0, 0},
{4, TokenOdinKind_i128be},
{4, TokenOdinKind_jmag},
{4, TokenOdinKind_string},
{4, TokenOdinKind_if},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{4, TokenOdinKind_i8le},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{4, TokenOdinKind_delete_cstring},
{0, 0},
{0, 0},
{4, TokenOdinKind_any},
{4, TokenOdinKind_u16},
{4, TokenOdinKind_reserve_dynamic_array},
{4, TokenOdinKind_else},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{4, TokenOdinKind_complex},
{0, 0},
{0, 0},
{4, TokenOdinKind_case},
{4, TokenOdinKind_b16},
{4, TokenOdinKind_uint},
{4, TokenOdinKind_init_global_temporary_allocator},
{0, 0},
{4, TokenOdinKind_u32be},
{0, 0},
{0, 0},
{4, TokenOdinKind_append_soa_elem},
{4, TokenOdinKind_i64},
{0, 0},
{0, 0},
{4, TokenOdinKind_i32le},
{0, 0},
{0, 0},
{4, TokenOdinKind_cast},
{4, TokenOdinKind_incl_elems},
{4, TokenOdinKind_bit_field},
{0, 0},
{0, 0},
{4, TokenOdinKind_resize},
{4, TokenOdinKind_break},
{4, TokenOdinKind_no_inline},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{4, TokenOdinKind_append_elem},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{4, TokenOdinKind_append_elems},
{4, TokenOdinKind_not_in},
{4, TokenOdinKind_expand_to_tuple},
{4, TokenOdinKind_byte},
{0, 0},
{0, 0},
{0, 0},
{4, TokenOdinKind_struct},
{4, TokenOdinKind_complex128},
{4, TokenOdinKind_b64},
{0, 0},
{0, 0},
{4, TokenOdinKind_make_map},
{4, TokenOdinKind_i128le},
{4, TokenOdinKind_copy},
{0, 0},
{4, TokenOdinKind_reserve},
{4, TokenOdinKind_u8le},
{0, 0},
{0, 0},
{0, 0},
{4, TokenOdinKind_transmute},
{4, TokenOdinKind_bool},
{0, 0},
{0, 0},
{0, 0},
{4, TokenOdinKind_enum},
{0, 0},
{4, TokenOdinKind_map},
{0, 0},
{0, 0},
{0, 0},
{4, TokenOdinKind_i8},
{4, TokenOdinKind_excl_elem},
{0, 0},
{4, TokenOdinKind_b8},
{4, TokenOdinKind_cap},
{4, TokenOdinKind_max},
{4, TokenOdinKind_new_clone},
{4, TokenOdinKind_reserve_soa},
{0, 0},
{4, TokenOdinKind_unoredered_remove},
{4, TokenOdinKind_type_info_of},
{4, TokenOdinKind_imag},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{4, TokenOdinKind_delete_dynamic_array},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{4, TokenOdinKind_incl_elem},
{0, 0},
{4, TokenOdinKind_u128le},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{4, TokenOdinKind_do},
{4, TokenOdinKind_proc},
{4, TokenOdinKind_u8},
{4, TokenOdinKind_complex64},
{4, TokenOdinKind_u128},
{0, 0},
{4, TokenOdinKind_u16be},
{0, 0},
{4, TokenOdinKind_package},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
};
i32 odin_main_keys_slot_count = 343;
u64 odin_main_keys_seed = 0x56651112c47efa45;
u64 odin_directives_hash_array[35] = {
0xdfcc5102be5353f5,0x0000000000000000,0xdfcc5102bc1a67f1,0x0a67a9c9511634cd,
0x04f93298ea089d33,0x0000000000000000,0x0000000000000000,0x167510f09cc627f5,
0x1b998ebbe6aa51ad,0x0000000000000000,0x0000000000000000,0x515469d0753531d7,
0x0000000000000000,0xc93bdd3675c71cbd,0x973a964cf1162d5f,0x0000000000000000,
0x04f9164ab1042aeb,0xb21883bc4f50cfaf,0x9dfaa64acb3769f3,0x0000000000000000,
0x973a97d9902651ff,0x0000000000000000,0x973a97d14802d14b,0x0000000000000000,
0x0000000000000000,0xdfcc5102be4166d1,0x9dfaa3d3af768bcb,0x0000000000000000,
0x4cf0e76c4350cfaf,0x973a97dd2d7e01d3,0x51847a46b736f14d,0x0000000000000000,
0x04f90c078ac3c3c1,0x0000000000000000,0xdfcc5102be50e6b3,
};
u8 odin_directives_key_array_0[] = {0x6c,0x69,0x6e,0x65,};
u8 odin_directives_key_array_2[] = {0x74,0x79,0x70,0x65,};
u8 odin_directives_key_array_3[] = {0x72,0x61,0x77,0x5f,0x75,0x6e,0x69,0x6f,0x6e,};
u8 odin_directives_key_array_4[] = {0x6e,0x6f,0x5f,0x61,0x6c,0x69,0x61,0x73,};
u8 odin_directives_key_array_7[] = {0x66,0x6f,0x72,0x63,0x65,0x5f,0x69,0x6e,0x6c,0x69,0x6e,0x65,};
u8 odin_directives_key_array_8[] = {0x61,0x6c,0x69,0x67,0x6e,};
u8 odin_directives_key_array_11[] = {0x6c,0x6f,0x63,0x61,0x74,0x69,0x6f,0x6e,0x73,};
u8 odin_directives_key_array_13[] = {0x63,0x61,0x6c,0x6c,0x65,0x72,0x5f,0x6c,0x6f,0x63,0x61,0x74,0x69,0x6f,0x6e,};
u8 odin_directives_key_array_14[] = {0x75,0x6e,0x72,0x6f,0x6c,0x6c,};
u8 odin_directives_key_array_16[] = {0x63,0x5f,0x76,0x61,0x72,0x61,0x72,0x67,};
u8 odin_directives_key_array_17[] = {0x6e,0x6f,0x5f,0x62,0x6f,0x75,0x6e,0x64,0x73,0x5f,0x63,0x68,0x65,0x63,0x6b,};
u8 odin_directives_key_array_18[] = {0x64,0x65,0x66,0x69,0x6e,0x65,0x64,};
u8 odin_directives_key_array_20[] = {0x61,0x73,0x73,0x65,0x72,0x74,};
u8 odin_directives_key_array_22[] = {0x6e,0x6f,0x5f,0x6e,0x69,0x6c,};
u8 odin_directives_key_array_25[] = {0x66,0x69,0x6c,0x65,};
u8 odin_directives_key_array_26[] = {0x70,0x61,0x72,0x74,0x69,0x61,0x6c,};
u8 odin_directives_key_array_28[] = {0x62,0x6f,0x75,0x6e,0x64,0x73,0x5f,0x63,0x68,0x65,0x63,0x6b,};
u8 odin_directives_key_array_29[] = {0x70,0x61,0x63,0x6b,0x65,0x64,};
u8 odin_directives_key_array_30[] = {0x70,0x72,0x6f,0x63,0x65,0x64,0x75,0x72,0x65,};
u8 odin_directives_key_array_32[] = {0x63,0x6f,0x6d,0x70,0x6c,0x65,0x74,0x65,};
u8 odin_directives_key_array_34[] = {0x6c,0x6f,0x61,0x64,};
String_Const_u8 odin_directives_key_array[35] = {
{odin_directives_key_array_0, 4},
{0, 0},
{odin_directives_key_array_2, 4},
{odin_directives_key_array_3, 9},
{odin_directives_key_array_4, 8},
{0, 0},
{0, 0},
{odin_directives_key_array_7, 12},
{odin_directives_key_array_8, 5},
{0, 0},
{0, 0},
{odin_directives_key_array_11, 9},
{0, 0},
{odin_directives_key_array_13, 15},
{odin_directives_key_array_14, 6},
{0, 0},
{odin_directives_key_array_16, 8},
{odin_directives_key_array_17, 15},
{odin_directives_key_array_18, 7},
{0, 0},
{odin_directives_key_array_20, 6},
{0, 0},
{odin_directives_key_array_22, 6},
{0, 0},
{0, 0},
{odin_directives_key_array_25, 4},
{odin_directives_key_array_26, 7},
{0, 0},
{odin_directives_key_array_28, 12},
{odin_directives_key_array_29, 6},
{odin_directives_key_array_30, 9},
{0, 0},
{odin_directives_key_array_32, 8},
{0, 0},
{odin_directives_key_array_34, 4},
};
Lexeme_Table_Value odin_directives_value_array[35] = {
{4, TokenOdinKind_line},
{0, 0},
{4, TokenOdinKind_type},
{4, TokenOdinKind_raw_union},
{4, TokenOdinKind_no_alias},
{0, 0},
{0, 0},
{4, TokenOdinKind_force_inline},
{4, TokenOdinKind_align},
{0, 0},
{0, 0},
{4, TokenOdinKind_locations},
{0, 0},
{4, TokenOdinKind_caller_location},
{4, TokenOdinKind_unroll},
{0, 0},
{4, TokenOdinKind_c_vararg},
{4, TokenOdinKind_no_bounds_check},
{4, TokenOdinKind_defined},
{0, 0},
{4, TokenOdinKind_assert},
{0, 0},
{4, TokenOdinKind_no_nil},
{0, 0},
{0, 0},
{4, TokenOdinKind_file},
{4, TokenOdinKind_partial},
{0, 0},
{4, TokenOdinKind_bounds_check},
{4, TokenOdinKind_packed},
{4, TokenOdinKind_procedure},
{0, 0},
{4, TokenOdinKind_complete},
{0, 0},
{4, TokenOdinKind_load},
};
i32 odin_directives_slot_count = 35;
u64 odin_directives_seed = 0x303f341765ce8d6f;
u64 odin_attributes_hash_array[21] = {
0x0000000000000000,0xff1264c5a5436e2b,0x59048b4f156775ad,0x222b00da4a1eea43,
0x0000000000000000,0xd0b76ce108232dc1,0x9a77956d3e4826bd,0x0000000000000000,
0x0000000000000000,0xff1264c42e692da3,0xacb1a648d4e141ad,0x197ee4ff97c2c7b5,
0x0000000000000000,0xe87546f887292c83,0x0000000000000000,0x0000000000000000,
0x804c50ae8ab91447,0x39ff28b4e1ba4351,0x0000000000000000,0x5ea2f62b51c2d867,
0x5ea2f812ec6a6bf3,
};
u8 odin_attributes_key_array_1[] = {0x73,0x74,0x61,0x74,0x69,0x63,};
u8 odin_attributes_key_array_2[] = {0x6c,0x69,0x6e,0x6b,0x5f,0x6e,0x61,0x6d,0x65,};
u8 odin_attributes_key_array_3[] = {0x64,0x65,0x66,0x65,0x72,0x72,0x65,0x64,0x5f,0x69,0x6e,};
u8 odin_attributes_key_array_5[] = {0x64,0x65,0x70,0x72,0x65,0x63,0x61,0x74,0x65,0x64,};
u8 odin_attributes_key_array_6[] = {0x64,0x65,0x66,0x65,0x72,0x72,0x65,0x64,0x5f,0x6f,0x75,0x74,};
u8 odin_attributes_key_array_9[] = {0x65,0x78,0x70,0x6f,0x72,0x74,};
u8 odin_attributes_key_array_10[] = {0x74,0x68,0x72,0x65,0x61,0x64,0x5f,0x6c,0x6f,0x63,0x61,0x6c,};
u8 odin_attributes_key_array_11[] = {0x6c,0x69,0x6e,0x6b,0x5f,0x70,0x72,0x65,0x66,0x69,0x78,};
u8 odin_attributes_key_array_13[] = {0x64,0x65,0x66,0x65,0x72,0x72,0x65,0x64,0x5f,0x6e,0x6f,0x6e,0x65,};
u8 odin_attributes_key_array_16[] = {0x64,0x65,0x66,0x61,0x75,0x6c,0x74,0x5f,0x63,0x61,0x6c,0x6c,0x69,0x6e,0x67,0x5f,0x63,0x6f,0x6e,0x76,0x65,0x6e,0x74,0x69,0x6f,0x6e,};
u8 odin_attributes_key_array_17[] = {0x72,0x65,0x71,0x75,0x69,0x72,0x65,0x5f,0x72,0x65,0x73,0x75,0x6c,0x74,0x73,};
u8 odin_attributes_key_array_19[] = {0x62,0x75,0x69,0x6c,0x74,0x69,0x6e,};
u8 odin_attributes_key_array_20[] = {0x70,0x72,0x69,0x76,0x61,0x74,0x65,};
String_Const_u8 odin_attributes_key_array[21] = {
{0, 0},
{odin_attributes_key_array_1, 6},
{odin_attributes_key_array_2, 9},
{odin_attributes_key_array_3, 11},
{0, 0},
{odin_attributes_key_array_5, 10},
{odin_attributes_key_array_6, 12},
{0, 0},
{0, 0},
{odin_attributes_key_array_9, 6},
{odin_attributes_key_array_10, 12},
{odin_attributes_key_array_11, 11},
{0, 0},
{odin_attributes_key_array_13, 13},
{0, 0},
{0, 0},
{odin_attributes_key_array_16, 26},
{odin_attributes_key_array_17, 15},
{0, 0},
{odin_attributes_key_array_19, 7},
{odin_attributes_key_array_20, 7},
};
Lexeme_Table_Value odin_attributes_value_array[21] = {
{0, 0},
{4, TokenOdinKind_static},
{4, TokenOdinKind_link_name},
{4, TokenOdinKind_deferred_in},
{0, 0},
{4, TokenOdinKind_deprecated},
{4, TokenOdinKind_deferred_out},
{0, 0},
{0, 0},
{4, TokenOdinKind_export},
{4, TokenOdinKind_thread_local},
{4, TokenOdinKind_link_prefix},
{0, 0},
{4, TokenOdinKind_deferred_none},
{0, 0},
{0, 0},
{4, TokenOdinKind_default_calling_convention},
{4, TokenOdinKind_require_results},
{0, 0},
{4, TokenOdinKind_builtin},
{4, TokenOdinKind_private},
};
i32 odin_attributes_slot_count = 21;
u64 odin_attributes_seed = 0xd87363685f63bc4e;
struct Lex_State_Odin{
u32 flags_ZF0;
u32 flags_KF0;
u16 flags_KB0;
u8 *base;
u8 *delim_first;
u8 *delim_one_past_last;
u8 *emit_ptr;
u8 *ptr;
u8 *opl_ptr;
};
internal void
lex_full_input_odin_init(Lex_State_Odin *state_ptr, String_Const_u8 input){
state_ptr->flags_ZF0 = 0;
state_ptr->flags_KF0 = 0;
state_ptr->flags_KB0 = 0;
state_ptr->base = input.str;
state_ptr->delim_first = input.str;
state_ptr->delim_one_past_last = input.str;
state_ptr->emit_ptr = input.str;
state_ptr->ptr = input.str;
state_ptr->opl_ptr = input.str + input.size;
}
internal b32
lex_full_input_odin_breaks(Arena *arena, Token_List *list, Lex_State_Odin *state_ptr, u64 max){
b32 result = false;
u64 emit_counter = 0;
Lex_State_Odin state;
block_copy_struct(&state, state_ptr);
{
state_label_1: // root
if (state.ptr == state.opl_ptr){
if ((true)){
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
token.flags = state.flags_KB0;
do{
token.sub_kind = TokenOdinKind_EOF;
token.kind = 0;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
}
state.flags_KF0 |= 0x1;
state.flags_ZF0 = 0;
result = true;
goto end;
}
}
switch (*state.ptr){
case 0x00:case 0x01:case 0x02:case 0x03:case 0x04:case 0x05:case 0x06:
case 0x07:case 0x08:case 0x0e:case 0x0f:case 0x10:case 0x11:case 0x12:
case 0x13:case 0x14:case 0x15:case 0x16:case 0x17:case 0x18:case 0x19:
case 0x1a:case 0x1b:case 0x1c:case 0x1d:case 0x1e:case 0x1f:case 0x5c:
case 0x7f:
{
state.ptr += 1;
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
token.flags = state.flags_KB0;
do{
token.sub_kind = TokenOdinKind_LexError;
token.kind = 2;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_KF0 |= 0x1;
state.flags_ZF0 = 0;
goto state_label_1; // root
}break;
case 0x09:case 0x0b:case 0x0c:case 0x20:
{
state.ptr += 1;
goto state_label_3; // whitespace
}break;
case 0x0a:
{
state.ptr += 1;
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
token.flags = state.flags_KB0;
do{
token.sub_kind = TokenOdinKind_EOL;
token.kind = 1;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_KF0 |= 0x1;
state.flags_ZF0 = 0;
goto state_label_1; // root
}break;
case 0x0d:
{
state.ptr += 1;
goto state_label_4; // carriage_return
}break;
case 0x21:
{
state.ptr += 1;
goto state_label_32; // op stage
}break;
case 0x22:
{
state.ptr += 1;
goto state_label_20; // string
}break;
case 0x23:
{
state.ptr += 1;
state.delim_first = state.ptr;
goto state_label_27; // directive
}break;
default:
{
state.ptr += 1;
goto state_label_2; // identifier
}break;
case 0x25:
{
state.ptr += 1;
goto state_label_38; // op stage
}break;
case 0x26:
{
state.ptr += 1;
goto state_label_33; // op stage
}break;
case 0x27:
{
state.ptr += 1;
state.flags_ZF0 |= 0x10;
goto state_label_20; // string
}break;
case 0x28:
{
state.ptr += 1;
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
token.flags = state.flags_KB0;
do{
token.sub_kind = TokenOdinKind_ParenOp;
token.kind = 13;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_KF0 |= 0x1;
state.flags_ZF0 = 0;
goto state_label_1; // root
}break;
case 0x29:
{
if ((HasFlag(state.flags_KB0, 0x1))){
state.ptr += 1;
state.flags_KB0 &= ~(0x1);
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
token.flags = state.flags_KB0;
do{
token.sub_kind = TokenOdinKind_AttributeClose;
token.kind = 14;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_KF0 |= 0x1;
state.flags_ZF0 = 0;
goto state_label_1; // root
}
state.ptr += 1;
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
token.flags = state.flags_KB0;
do{
token.sub_kind = TokenOdinKind_ParenCl;
token.kind = 14;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_KF0 |= 0x1;
state.flags_ZF0 = 0;
goto state_label_1; // root
}break;
case 0x2a:
{
state.ptr += 1;
goto state_label_37; // op stage
}break;
case 0x2b:
{
state.ptr += 1;
goto state_label_35; // op stage
}break;
case 0x2c:
{
state.ptr += 1;
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
token.flags = state.flags_KB0;
do{
token.sub_kind = TokenOdinKind_Comma;
token.kind = 15;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_KF0 |= 0x1;
state.flags_ZF0 = 0;
goto state_label_1; // root
}break;
case 0x2d:
{
state.ptr += 1;
goto state_label_36; // op stage
}break;
case 0x2e:
{
state.ptr += 1;
goto state_label_5; // operator_or_fnumber_dot
}break;
case 0x2f:
{
state.ptr += 1;
goto state_label_6; // operator_or_comment_slash
}break;
case 0x30:
{
state.ptr += 1;
goto state_label_8; // znumber
}break;
case 0x31:case 0x32:case 0x33:case 0x34:case 0x35:case 0x36:case 0x37:
case 0x38:case 0x39:
{
state.ptr += 1;
goto state_label_7; // number
}break;
case 0x3a:
{
state.ptr += 1;
goto state_label_28; // op stage
}break;
case 0x3b:
{
state.ptr += 1;
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
token.flags = state.flags_KB0;
do{
token.sub_kind = TokenOdinKind_Semicolon;
token.kind = 15;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_KF0 |= 0x1;
state.flags_ZF0 = 0;
goto state_label_1; // root
}break;
case 0x3c:
{
state.ptr += 1;
goto state_label_29; // op stage
}break;
case 0x3d:
{
state.ptr += 1;
goto state_label_31; // op stage
}break;
case 0x3e:
{
state.ptr += 1;
goto state_label_30; // op stage
}break;
case 0x3f:
{
state.ptr += 1;
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
token.flags = state.flags_KB0;
do{
token.sub_kind = TokenOdinKind_Ternary;
token.kind = 7;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_KF0 |= 0x1;
state.flags_ZF0 = 0;
goto state_label_1; // root
}break;
case 0x40:
{
state.ptr += 1;
state.delim_first = state.ptr;
goto state_label_25; // attribute_first
}break;
case 0x5b:
{
state.ptr += 1;
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
token.flags = state.flags_KB0;
do{
token.sub_kind = TokenOdinKind_BrackOp;
token.kind = 13;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_KF0 |= 0x1;
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
token.flags = state.flags_KB0;
do{
token.sub_kind = TokenOdinKind_BrackCl;
token.kind = 14;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_KF0 |= 0x1;
state.flags_ZF0 = 0;
goto state_label_1; // root
}break;
case 0x5e:
{
state.ptr += 1;
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
token.flags = state.flags_KB0;
do{
token.sub_kind = TokenOdinKind_Carrot;
token.kind = 7;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_KF0 |= 0x1;
state.flags_ZF0 = 0;
goto state_label_1; // root
}break;
case 0x60:
{
state.ptr += 1;
state.flags_ZF0 |= 0x20;
goto state_label_20; // string
}break;
case 0x7b:
{
state.ptr += 1;
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
token.flags = state.flags_KB0;
do{
token.sub_kind = TokenOdinKind_BraceOp;
token.kind = 11;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_KF0 |= 0x1;
state.flags_ZF0 = 0;
goto state_label_1; // root
}break;
case 0x7c:
{
state.ptr += 1;
goto state_label_34; // op stage
}break;
case 0x7d:
{
state.ptr += 1;
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
token.flags = state.flags_KB0;
do{
token.sub_kind = TokenOdinKind_BraceCl;
token.kind = 12;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_KF0 |= 0x1;
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
token.flags = state.flags_KB0;
do{
token.sub_kind = TokenOdinKind_Tilde;
token.kind = 7;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_KF0 |= 0x1;
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
token.flags = state.flags_KB0;
do{
if (HasFlag(state.flags_KB0, 0x1)){
Lexeme_Table_Lookup lookup = lexeme_table_lookup(odin_attributes_hash_array, odin_attributes_key_array, odin_attributes_value_array, odin_attributes_slot_count, odin_attributes_seed, state.emit_ptr, token.size);
if (lookup.found_match){
token.kind = lookup.base_kind;
token.sub_kind = lookup.sub_kind;
break;
}
}
Lexeme_Table_Lookup lookup = lexeme_table_lookup(odin_main_keys_hash_array, odin_main_keys_key_array, odin_main_keys_value_array, odin_main_keys_slot_count, odin_main_keys_seed, state.emit_ptr, token.size);
if (lookup.found_match){
token.kind = lookup.base_kind;
token.sub_kind = lookup.sub_kind;
break;
}
token.sub_kind = TokenOdinKind_Identifier;
token.kind = 6;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
}
state.flags_KF0 |= 0x1;
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
case 0x23:case 0x25:case 0x26:case 0x27:case 0x28:case 0x29:case 0x2a:
case 0x2b:case 0x2c:case 0x2d:case 0x2e:case 0x2f:case 0x3a:case 0x3b:
case 0x3c:case 0x3d:case 0x3e:case 0x3f:case 0x40:case 0x5b:case 0x5c:
case 0x5d:case 0x5e:case 0x60:case 0x7b:case 0x7c:case 0x7d:case 0x7e:
case 0x7f:
{
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
token.flags = state.flags_KB0;
do{
if (HasFlag(state.flags_KB0, 0x1)){
Lexeme_Table_Lookup lookup = lexeme_table_lookup(odin_attributes_hash_array, odin_attributes_key_array, odin_attributes_value_array, odin_attributes_slot_count, odin_attributes_seed, state.emit_ptr, token.size);
if (lookup.found_match){
token.kind = lookup.base_kind;
token.sub_kind = lookup.sub_kind;
break;
}
}
Lexeme_Table_Lookup lookup = lexeme_table_lookup(odin_main_keys_hash_array, odin_main_keys_key_array, odin_main_keys_value_array, odin_main_keys_slot_count, odin_main_keys_seed, state.emit_ptr, token.size);
if (lookup.found_match){
token.kind = lookup.base_kind;
token.sub_kind = lookup.sub_kind;
break;
}
token.sub_kind = TokenOdinKind_Identifier;
token.kind = 6;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_KF0 |= 0x1;
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
token.flags = state.flags_KB0;
do{
token.sub_kind = TokenOdinKind_Whitespace;
token.kind = 1;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
}
state.flags_KF0 |= 0x1;
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
token.flags = state.flags_KB0;
do{
token.sub_kind = TokenOdinKind_Whitespace;
token.kind = 1;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_KF0 |= 0x1;
state.flags_ZF0 = 0;
goto state_label_1; // root
}break;
case 0x09:case 0x0b:case 0x0c:case 0x20:
{
state.ptr += 1;
goto state_label_3; // whitespace
}break;
case 0x0a:
{
state.ptr += 1;
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
token.flags = state.flags_KB0;
do{
token.sub_kind = TokenOdinKind_EOL;
token.kind = 1;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_KF0 |= 0x1;
state.flags_ZF0 = 0;
goto state_label_1; // root
}break;
case 0x0d:
{
state.ptr += 1;
goto state_label_4; // carriage_return
}break;
}
}
{
state_label_4: // carriage_return
if (state.ptr == state.opl_ptr){
if ((true)){
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
token.flags = state.flags_KB0;
do{
token.sub_kind = TokenOdinKind_Whitespace;
token.kind = 1;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
}
state.flags_KF0 |= 0x1;
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
token.flags = state.flags_KB0;
do{
token.sub_kind = TokenOdinKind_Whitespace;
token.kind = 1;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_KF0 |= 0x1;
state.flags_ZF0 = 0;
goto state_label_1; // root
}break;
case 0x0a:
{
state.ptr += 1;
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
token.flags = state.flags_KB0;
do{
token.sub_kind = TokenOdinKind_EOL;
token.kind = 1;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_KF0 |= 0x1;
state.flags_ZF0 = 0;
goto state_label_1; // root
}break;
}
}
{
state_label_5: // operator_or_fnumber_dot
if (state.ptr == state.opl_ptr){
if ((true)){
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
token.flags = state.flags_KB0;
do{
token.sub_kind = TokenOdinKind_Dot;
token.kind = 7;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
}
state.flags_KF0 |= 0x1;
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
token.flags = state.flags_KB0;
do{
token.sub_kind = TokenOdinKind_Dot;
token.kind = 7;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_KF0 |= 0x1;
state.flags_ZF0 = 0;
goto state_label_1; // root
}break;
case 0x2e:
{
state.ptr += 1;
goto state_label_41; // op stage
}break;
case 0x30:case 0x31:case 0x32:case 0x33:case 0x34:case 0x35:case 0x36:
case 0x37:case 0x38:case 0x39:
{
state.ptr += 1;
goto state_label_9; // fnumber_decimal
}break;
}
}
{
state_label_6: // operator_or_comment_slash
if (state.ptr == state.opl_ptr){
if ((true)){
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
token.flags = state.flags_KB0;
do{
token.sub_kind = TokenOdinKind_Div;
token.kind = 7;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
}
state.flags_KF0 |= 0x1;
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
token.flags = state.flags_KB0;
do{
token.sub_kind = TokenOdinKind_Div;
token.kind = 7;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_KF0 |= 0x1;
state.flags_ZF0 = 0;
goto state_label_1; // root
}break;
case 0x2a:
{
state.ptr += 1;
goto state_label_22; // comment_block
}break;
case 0x2f:
{
state.ptr += 1;
goto state_label_24; // comment_line
}break;
case 0x3d:
{
state.ptr += 1;
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
token.flags = state.flags_KB0;
do{
token.sub_kind = TokenOdinKind_DivEq;
token.kind = 7;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_KF0 |= 0x1;
state.flags_ZF0 = 0;
goto state_label_1; // root
}break;
}
}
{
state_label_7: // number
if (state.ptr == state.opl_ptr){
if ((true)){
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
token.flags = state.flags_KB0;
do{
token.sub_kind = TokenOdinKind_LiteralInteger;
token.kind = 8;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
}
state.flags_KF0 |= 0x1;
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
token.flags = state.flags_KB0;
do{
token.sub_kind = TokenOdinKind_LiteralInteger;
token.kind = 8;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_KF0 |= 0x1;
state.flags_ZF0 = 0;
goto state_label_1; // root
}break;
case 0x2e:
{
state.ptr += 1;
goto state_label_9; // fnumber_decimal
}break;
case 0x30:case 0x31:case 0x32:case 0x33:case 0x34:case 0x35:case 0x36:
case 0x37:case 0x38:case 0x39:
{
state.ptr += 1;
goto state_label_7; // number
}break;
case 0x45:case 0x65:
{
state.ptr += 1;
goto state_label_10; // fnumber_exponent
}break;
}
}
{
state_label_8: // znumber
if (state.ptr == state.opl_ptr){
if ((true)){
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
token.flags = state.flags_KB0;
do{
token.sub_kind = TokenOdinKind_LiteralInteger;
token.kind = 8;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
}
state.flags_KF0 |= 0x1;
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
token.flags = state.flags_KB0;
do{
token.sub_kind = TokenOdinKind_LiteralInteger;
token.kind = 8;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_KF0 |= 0x1;
state.flags_ZF0 = 0;
goto state_label_1; // root
}break;
case 0x2e:
{
state.ptr += 1;
goto state_label_9; // fnumber_decimal
}break;
case 0x42:case 0x62:
{
state.ptr += 1;
state.flags_ZF0 |= 0x8;
goto state_label_15; // number_bin_first
}break;
case 0x45:case 0x65:
{
state.ptr += 1;
goto state_label_10; // fnumber_exponent
}break;
case 0x4f:case 0x6f:
{
state.ptr += 1;
state.flags_ZF0 |= 0x2;
goto state_label_17; // number_oct
}break;
case 0x58:case 0x78:
{
state.ptr += 1;
state.flags_ZF0 |= 0x1;
goto state_label_13; // number_hex_first
}break;
case 0x5a:case 0x7a:
{
state.ptr += 1;
state.flags_ZF0 |= 0x4;
goto state_label_14; // number_doz_first
}break;
}
}
{
state_label_9: // fnumber_decimal
if (state.ptr == state.opl_ptr){
if ((true)){
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
token.flags = state.flags_KB0;
do{
token.sub_kind = TokenOdinKind_LiteralFloat;
token.kind = 9;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
}
state.flags_KF0 |= 0x1;
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
token.flags = state.flags_KB0;
do{
token.sub_kind = TokenOdinKind_LiteralFloat;
token.kind = 9;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_KF0 |= 0x1;
state.flags_ZF0 = 0;
goto state_label_1; // root
}break;
case 0x30:case 0x31:case 0x32:case 0x33:case 0x34:case 0x35:case 0x36:
case 0x37:case 0x38:case 0x39:
{
state.ptr += 1;
goto state_label_9; // fnumber_decimal
}break;
case 0x45:case 0x65:
{
state.ptr += 1;
goto state_label_10; // fnumber_exponent
}break;
}
}
{
state_label_10: // fnumber_exponent
if (state.ptr == state.opl_ptr){
if ((true)){
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
token.flags = state.flags_KB0;
do{
token.sub_kind = TokenOdinKind_LiteralFloat;
token.kind = 9;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
}
state.flags_KF0 |= 0x1;
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
token.flags = state.flags_KB0;
do{
token.sub_kind = TokenOdinKind_LiteralFloat;
token.kind = 9;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_KF0 |= 0x1;
state.flags_ZF0 = 0;
goto state_label_1; // root
}break;
case 0x2b:case 0x2d:
{
state.ptr += 1;
goto state_label_11; // fnumber_exponent_sign
}break;
case 0x30:case 0x31:case 0x32:case 0x33:case 0x34:case 0x35:case 0x36:
case 0x37:case 0x38:case 0x39:
{
state.ptr += 1;
goto state_label_12; // fnumber_exponent_digits
}break;
}
}
{
state_label_11: // fnumber_exponent_sign
if (state.ptr == state.opl_ptr){
if ((true)){
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
token.flags = state.flags_KB0;
do{
token.sub_kind = TokenOdinKind_LiteralFloat;
token.kind = 9;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
}
state.flags_KF0 |= 0x1;
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
token.flags = state.flags_KB0;
do{
token.sub_kind = TokenOdinKind_LiteralFloat;
token.kind = 9;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_KF0 |= 0x1;
state.flags_ZF0 = 0;
goto state_label_1; // root
}break;
case 0x30:case 0x31:case 0x32:case 0x33:case 0x34:case 0x35:case 0x36:
case 0x37:case 0x38:case 0x39:
{
state.ptr += 1;
goto state_label_12; // fnumber_exponent_digits
}break;
}
}
{
state_label_12: // fnumber_exponent_digits
if (state.ptr == state.opl_ptr){
if ((true)){
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
token.flags = state.flags_KB0;
do{
token.sub_kind = TokenOdinKind_LiteralFloat;
token.kind = 9;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
}
state.flags_KF0 |= 0x1;
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
token.flags = state.flags_KB0;
do{
token.sub_kind = TokenOdinKind_LiteralFloat;
token.kind = 9;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_KF0 |= 0x1;
state.flags_ZF0 = 0;
goto state_label_1; // root
}break;
case 0x30:case 0x31:case 0x32:case 0x33:case 0x34:case 0x35:case 0x36:
case 0x37:case 0x38:case 0x39:
{
state.ptr += 1;
goto state_label_12; // fnumber_exponent_digits
}break;
}
}
{
state_label_13: // number_hex_first
if (state.ptr == state.opl_ptr){
if ((true)){
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
token.flags = state.flags_KB0;
do{
token.sub_kind = TokenOdinKind_LexError;
token.kind = 2;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
}
state.flags_KF0 |= 0x1;
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
token.flags = state.flags_KB0;
do{
token.sub_kind = TokenOdinKind_LexError;
token.kind = 2;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_KF0 |= 0x1;
state.flags_ZF0 = 0;
goto state_label_1; // root
}break;
case 0x30:case 0x31:case 0x32:case 0x33:case 0x34:case 0x35:case 0x36:
case 0x37:case 0x38:case 0x39:case 0x41:case 0x42:case 0x43:case 0x44:
case 0x45:case 0x46:case 0x61:case 0x62:case 0x63:case 0x64:case 0x65:
case 0x66:
{
state.ptr += 1;
goto state_label_16; // number_hex
}break;
}
}
{
state_label_14: // number_doz_first
if (state.ptr == state.opl_ptr){
if ((true)){
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
token.flags = state.flags_KB0;
do{
token.sub_kind = TokenOdinKind_LexError;
token.kind = 2;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
}
state.flags_KF0 |= 0x1;
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
token.flags = state.flags_KB0;
do{
token.sub_kind = TokenOdinKind_LexError;
token.kind = 2;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_KF0 |= 0x1;
state.flags_ZF0 = 0;
goto state_label_1; // root
}break;
case 0x30:case 0x31:case 0x32:case 0x33:case 0x34:case 0x35:case 0x36:
case 0x37:case 0x38:case 0x39:case 0x41:case 0x42:case 0x61:case 0x62:
{
state.ptr += 1;
goto state_label_18; // number_doz
}break;
}
}
{
state_label_15: // number_bin_first
if (state.ptr == state.opl_ptr){
if ((true)){
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
token.flags = state.flags_KB0;
do{
token.sub_kind = TokenOdinKind_LexError;
token.kind = 2;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
}
state.flags_KF0 |= 0x1;
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
token.flags = state.flags_KB0;
do{
token.sub_kind = TokenOdinKind_LexError;
token.kind = 2;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_KF0 |= 0x1;
state.flags_ZF0 = 0;
goto state_label_1; // root
}break;
case 0x30:case 0x31:
{
state.ptr += 1;
goto state_label_19; // number_bin
}break;
case 0x5f:
{
state.ptr += 1;
state.flags_ZF0 |= 0x8;
goto state_label_15; // number_bin_first
}break;
}
}
{
state_label_16: // number_hex
if (state.ptr == state.opl_ptr){
if ((true)){
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
token.flags = state.flags_KB0;
do{
token.sub_kind = TokenOdinKind_LiteralIntegerHex;
token.kind = 8;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
}
state.flags_KF0 |= 0x1;
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
token.flags = state.flags_KB0;
do{
token.sub_kind = TokenOdinKind_LiteralIntegerHex;
token.kind = 8;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_KF0 |= 0x1;
state.flags_ZF0 = 0;
goto state_label_1; // root
}break;
case 0x30:case 0x31:case 0x32:case 0x33:case 0x34:case 0x35:case 0x36:
case 0x37:case 0x38:case 0x39:case 0x41:case 0x42:case 0x43:case 0x44:
case 0x45:case 0x46:case 0x61:case 0x62:case 0x63:case 0x64:case 0x65:
case 0x66:
{
state.ptr += 1;
goto state_label_16; // number_hex
}break;
}
}
{
state_label_17: // number_oct
if (state.ptr == state.opl_ptr){
if ((true)){
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
token.flags = state.flags_KB0;
do{
token.sub_kind = TokenOdinKind_LiteralIntegerOct;
token.kind = 8;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
}
state.flags_KF0 |= 0x1;
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
token.flags = state.flags_KB0;
do{
token.sub_kind = TokenOdinKind_LiteralIntegerOct;
token.kind = 8;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_KF0 |= 0x1;
state.flags_ZF0 = 0;
goto state_label_1; // root
}break;
case 0x30:case 0x31:case 0x32:case 0x33:case 0x34:case 0x35:case 0x36:
case 0x37:
{
state.ptr += 1;
state.flags_ZF0 |= 0x2;
goto state_label_17; // number_oct
}break;
}
}
{
state_label_18: // number_doz
if (state.ptr == state.opl_ptr){
if ((true)){
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
token.flags = state.flags_KB0;
do{
token.sub_kind = TokenOdinKind_LiteralIntegerDoz;
token.kind = 8;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
}
state.flags_KF0 |= 0x1;
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
token.flags = state.flags_KB0;
do{
token.sub_kind = TokenOdinKind_LiteralIntegerDoz;
token.kind = 8;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_KF0 |= 0x1;
state.flags_ZF0 = 0;
goto state_label_1; // root
}break;
case 0x30:case 0x31:case 0x32:case 0x33:case 0x34:case 0x35:case 0x36:
case 0x37:case 0x38:case 0x39:case 0x41:case 0x42:case 0x43:case 0x44:
case 0x45:case 0x46:case 0x61:case 0x62:case 0x63:case 0x64:case 0x65:
case 0x66:
{
state.ptr += 1;
goto state_label_18; // number_doz
}break;
}
}
{
state_label_19: // number_bin
if (state.ptr == state.opl_ptr){
if ((true)){
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
token.flags = state.flags_KB0;
do{
token.sub_kind = TokenOdinKind_LiteralIntegerBin;
token.kind = 8;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
}
state.flags_KF0 |= 0x1;
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
token.flags = state.flags_KB0;
do{
token.sub_kind = TokenOdinKind_LiteralIntegerBin;
token.kind = 8;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_KF0 |= 0x1;
state.flags_ZF0 = 0;
goto state_label_1; // root
}break;
case 0x30:case 0x31:case 0x5f:
{
state.ptr += 1;
goto state_label_19; // number_bin
}break;
}
}
{
state_label_20: // string
if (state.ptr == state.opl_ptr){
if ((true)){
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
token.flags = state.flags_KB0;
do{
token.sub_kind = TokenOdinKind_LexError;
token.kind = 2;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
}
state.flags_KF0 |= 0x1;
state.flags_ZF0 = 0;
goto state_label_1; // root
}
}
switch (*state.ptr){
default:
{
state.ptr += 1;
goto state_label_20; // string
}break;
case 0x0a:
{
if ((!HasFlag(state.flags_ZF0, 0x20))){
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
token.flags = state.flags_KB0;
do{
token.sub_kind = TokenOdinKind_LexError;
token.kind = 2;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_KF0 |= 0x1;
state.flags_ZF0 = 0;
goto state_label_1; // root
}
state.ptr += 1;
goto state_label_20; // string
}break;
case 0x22:
{
if ((!HasFlag(state.flags_ZF0, 0x10))){
state.ptr += 1;
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
token.flags = state.flags_KB0;
do{
token.sub_kind = TokenOdinKind_LiteralString;
token.kind = 10;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_KF0 |= 0x1;
state.flags_ZF0 = 0;
goto state_label_1; // root
}
state.ptr += 1;
goto state_label_20; // string
}break;
case 0x27:
{
if ((HasFlag(state.flags_ZF0, 0x10))){
state.ptr += 1;
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
token.flags = state.flags_KB0;
do{
token.sub_kind = TokenOdinKind_LiteralCharacter;
token.kind = 10;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_KF0 |= 0x1;
state.flags_ZF0 = 0;
goto state_label_1; // root
}
if ((!HasFlag(state.flags_ZF0, 0x20) && !HasFlag(state.flags_ZF0, 0x10))){
state.ptr += 1;
goto state_label_20; // string
}
state.ptr += 1;
goto state_label_20; // string
}break;
case 0x5c:
{
if ((!HasFlag(state.flags_ZF0, 0x20))){
state.ptr += 1;
goto state_label_21; // string_esc
}
state.ptr += 1;
goto state_label_20; // string
}break;
case 0x60:
{
if ((HasFlag(state.flags_ZF0, 0x20))){
state.ptr += 1;
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
token.flags = state.flags_KB0;
do{
token.sub_kind = TokenOdinKind_LiteralStringRaw;
token.kind = 10;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_KF0 |= 0x1;
state.flags_ZF0 = 0;
goto state_label_1; // root
}
state.ptr += 1;
goto state_label_20; // string
}break;
}
}
{
state_label_21: // string_esc
if (state.ptr == state.opl_ptr){
if ((true)){
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
token.flags = state.flags_KB0;
do{
token.sub_kind = TokenOdinKind_LexError;
token.kind = 2;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
}
state.flags_KF0 |= 0x1;
state.flags_ZF0 = 0;
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
token.flags = state.flags_KB0;
do{
token.sub_kind = TokenOdinKind_EOF;
token.kind = 0;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
}
state.flags_KF0 |= 0x1;
state.flags_ZF0 = 0;
result = true;
goto end;
}
}
switch (*state.ptr){
default:
{
state.ptr += 1;
goto state_label_20; // string
}break;
}
}
{
state_label_22: // comment_block
if (state.ptr == state.opl_ptr){
if ((true)){
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
token.flags = state.flags_KB0;
do{
token.sub_kind = TokenOdinKind_BlockComment;
token.kind = 3;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
}
state.flags_KF0 |= 0x1;
state.flags_ZF0 = 0;
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
token.flags = state.flags_KB0;
do{
token.sub_kind = TokenOdinKind_EOF;
token.kind = 0;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
}
state.flags_KF0 |= 0x1;
state.flags_ZF0 = 0;
result = true;
goto end;
}
}
switch (*state.ptr){
default:
{
state.ptr += 1;
goto state_label_22; // comment_block
}break;
case 0x2a:
{
state.ptr += 1;
goto state_label_23; // comment_block_try_close
}break;
}
}
{
state_label_23: // comment_block_try_close
if (state.ptr == state.opl_ptr){
if ((true)){
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
token.flags = state.flags_KB0;
do{
token.sub_kind = TokenOdinKind_BlockComment;
token.kind = 3;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
}
state.flags_KF0 |= 0x1;
state.flags_ZF0 = 0;
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
token.flags = state.flags_KB0;
do{
token.sub_kind = TokenOdinKind_EOF;
token.kind = 0;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
}
state.flags_KF0 |= 0x1;
state.flags_ZF0 = 0;
result = true;
goto end;
}
}
switch (*state.ptr){
default:
{
state.ptr += 1;
goto state_label_22; // comment_block
}break;
case 0x2a:
{
state.ptr += 1;
goto state_label_23; // comment_block_try_close
}break;
case 0x2f:
{
state.ptr += 1;
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
token.flags = state.flags_KB0;
do{
token.sub_kind = TokenOdinKind_BlockComment;
token.kind = 3;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_KF0 |= 0x1;
state.flags_ZF0 = 0;
goto state_label_1; // root
}break;
}
}
{
state_label_24: // comment_line
if (state.ptr == state.opl_ptr){
if ((true)){
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
token.flags = state.flags_KB0;
do{
token.sub_kind = TokenOdinKind_LineComment;
token.kind = 3;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
}
state.flags_KF0 |= 0x1;
state.flags_ZF0 = 0;
goto state_label_1; // root
}
}
switch (*state.ptr){
default:
{
state.ptr += 1;
goto state_label_24; // comment_line
}break;
case 0x0a:
{
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
token.flags = state.flags_KB0;
do{
token.sub_kind = TokenOdinKind_LineComment;
token.kind = 3;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_KF0 |= 0x1;
state.flags_ZF0 = 0;
goto state_label_1; // root
}break;
}
}
{
state_label_25: // attribute_first
if (state.ptr == state.opl_ptr){
if ((true)){
goto state_label_26; // attribute
}
}
switch (*state.ptr){
default:
{
goto state_label_26; // attribute
}break;
case 0x28:
{
state.ptr += 1;
state.flags_KB0 |= 0x1;
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
token.flags = state.flags_KB0;
do{
token.sub_kind = TokenOdinKind_AttributeOpen;
token.kind = 13;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_KF0 |= 0x1;
state.flags_ZF0 = 0;
goto state_label_1; // root
}break;
}
}
{
state_label_26: // attribute
if (state.ptr == state.opl_ptr){
if ((true)){
state.delim_one_past_last = state.ptr;
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
token.flags = state.flags_KB0;
do{
Lexeme_Table_Lookup lookup = lexeme_table_lookup(odin_attributes_hash_array, odin_attributes_key_array, odin_attributes_value_array, odin_attributes_slot_count, odin_attributes_seed, state.delim_first, (state.delim_one_past_last - state.delim_first));
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
state.flags_KF0 |= 0x1;
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
token.flags = state.flags_KB0;
do{
Lexeme_Table_Lookup lookup = lexeme_table_lookup(odin_attributes_hash_array, odin_attributes_key_array, odin_attributes_value_array, odin_attributes_slot_count, odin_attributes_seed, state.delim_first, (state.delim_one_past_last - state.delim_first));
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
state.flags_KF0 |= 0x1;
state.flags_ZF0 = 0;
goto state_label_1; // root
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
goto state_label_26; // attribute
}break;
}
}
{
state_label_27: // directive
if (state.ptr == state.opl_ptr){
if ((true)){
state.delim_one_past_last = state.ptr;
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
token.flags = state.flags_KB0;
do{
Lexeme_Table_Lookup lookup = lexeme_table_lookup(odin_directives_hash_array, odin_directives_key_array, odin_directives_value_array, odin_directives_slot_count, odin_directives_seed, state.delim_first, (state.delim_one_past_last - state.delim_first));
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
state.flags_KF0 |= 0x1;
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
token.flags = state.flags_KB0;
do{
Lexeme_Table_Lookup lookup = lexeme_table_lookup(odin_directives_hash_array, odin_directives_key_array, odin_directives_value_array, odin_directives_slot_count, odin_directives_seed, state.delim_first, (state.delim_one_past_last - state.delim_first));
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
state.flags_KF0 |= 0x1;
state.flags_ZF0 = 0;
goto state_label_1; // root
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
goto state_label_27; // directive
}break;
}
}
{
state_label_28: // op stage
if (state.ptr == state.opl_ptr){
if ((true)){
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
token.flags = state.flags_KB0;
do{
token.sub_kind = TokenOdinKind_Colon;
token.kind = 15;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
}
state.flags_KF0 |= 0x1;
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
token.flags = state.flags_KB0;
do{
token.sub_kind = TokenOdinKind_Colon;
token.kind = 15;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_KF0 |= 0x1;
state.flags_ZF0 = 0;
goto state_label_1; // root
}break;
case 0x3a:
{
state.ptr += 1;
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
token.flags = state.flags_KB0;
do{
token.sub_kind = TokenOdinKind_ColonColon;
token.kind = 7;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_KF0 |= 0x1;
state.flags_ZF0 = 0;
goto state_label_1; // root
}break;
}
}
{
state_label_29: // op stage
if (state.ptr == state.opl_ptr){
if ((true)){
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
token.flags = state.flags_KB0;
do{
token.sub_kind = TokenOdinKind_Less;
token.kind = 7;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
}
state.flags_KF0 |= 0x1;
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
token.flags = state.flags_KB0;
do{
token.sub_kind = TokenOdinKind_Less;
token.kind = 7;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_KF0 |= 0x1;
state.flags_ZF0 = 0;
goto state_label_1; // root
}break;
case 0x3c:
{
state.ptr += 1;
goto state_label_39; // op stage
}break;
case 0x3d:
{
state.ptr += 1;
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
token.flags = state.flags_KB0;
do{
token.sub_kind = TokenOdinKind_LessEq;
token.kind = 7;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_KF0 |= 0x1;
state.flags_ZF0 = 0;
goto state_label_1; // root
}break;
}
}
{
state_label_30: // op stage
if (state.ptr == state.opl_ptr){
if ((true)){
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
token.flags = state.flags_KB0;
do{
token.sub_kind = TokenOdinKind_Grtr;
token.kind = 7;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
}
state.flags_KF0 |= 0x1;
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
token.flags = state.flags_KB0;
do{
token.sub_kind = TokenOdinKind_Grtr;
token.kind = 7;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_KF0 |= 0x1;
state.flags_ZF0 = 0;
goto state_label_1; // root
}break;
case 0x3d:
{
state.ptr += 1;
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
token.flags = state.flags_KB0;
do{
token.sub_kind = TokenOdinKind_GrtrEq;
token.kind = 7;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_KF0 |= 0x1;
state.flags_ZF0 = 0;
goto state_label_1; // root
}break;
case 0x3e:
{
state.ptr += 1;
goto state_label_40; // op stage
}break;
}
}
{
state_label_31: // op stage
if (state.ptr == state.opl_ptr){
if ((true)){
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
token.flags = state.flags_KB0;
do{
token.sub_kind = TokenOdinKind_Eq;
token.kind = 7;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
}
state.flags_KF0 |= 0x1;
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
token.flags = state.flags_KB0;
do{
token.sub_kind = TokenOdinKind_Eq;
token.kind = 7;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_KF0 |= 0x1;
state.flags_ZF0 = 0;
goto state_label_1; // root
}break;
case 0x3d:
{
state.ptr += 1;
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
token.flags = state.flags_KB0;
do{
token.sub_kind = TokenOdinKind_EqEq;
token.kind = 7;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_KF0 |= 0x1;
state.flags_ZF0 = 0;
goto state_label_1; // root
}break;
}
}
{
state_label_32: // op stage
if (state.ptr == state.opl_ptr){
if ((true)){
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
token.flags = state.flags_KB0;
do{
token.sub_kind = TokenOdinKind_Not;
token.kind = 7;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
}
state.flags_KF0 |= 0x1;
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
token.flags = state.flags_KB0;
do{
token.sub_kind = TokenOdinKind_Not;
token.kind = 7;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_KF0 |= 0x1;
state.flags_ZF0 = 0;
goto state_label_1; // root
}break;
case 0x3d:
{
state.ptr += 1;
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
token.flags = state.flags_KB0;
do{
token.sub_kind = TokenOdinKind_NotEq;
token.kind = 7;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_KF0 |= 0x1;
state.flags_ZF0 = 0;
goto state_label_1; // root
}break;
}
}
{
state_label_33: // op stage
if (state.ptr == state.opl_ptr){
if ((true)){
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
token.flags = state.flags_KB0;
do{
token.sub_kind = TokenOdinKind_And;
token.kind = 7;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
}
state.flags_KF0 |= 0x1;
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
token.flags = state.flags_KB0;
do{
token.sub_kind = TokenOdinKind_And;
token.kind = 7;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_KF0 |= 0x1;
state.flags_ZF0 = 0;
goto state_label_1; // root
}break;
case 0x26:
{
state.ptr += 1;
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
token.flags = state.flags_KB0;
do{
token.sub_kind = TokenOdinKind_AndAnd;
token.kind = 7;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_KF0 |= 0x1;
state.flags_ZF0 = 0;
goto state_label_1; // root
}break;
}
}
{
state_label_34: // op stage
if (state.ptr == state.opl_ptr){
if ((true)){
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
token.flags = state.flags_KB0;
do{
token.sub_kind = TokenOdinKind_Or;
token.kind = 7;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
}
state.flags_KF0 |= 0x1;
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
token.flags = state.flags_KB0;
do{
token.sub_kind = TokenOdinKind_Or;
token.kind = 7;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_KF0 |= 0x1;
state.flags_ZF0 = 0;
goto state_label_1; // root
}break;
case 0x7c:
{
state.ptr += 1;
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
token.flags = state.flags_KB0;
do{
token.sub_kind = TokenOdinKind_OrOr;
token.kind = 7;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_KF0 |= 0x1;
state.flags_ZF0 = 0;
goto state_label_1; // root
}break;
}
}
{
state_label_35: // op stage
if (state.ptr == state.opl_ptr){
if ((true)){
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
token.flags = state.flags_KB0;
do{
token.sub_kind = TokenOdinKind_Plus;
token.kind = 7;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
}
state.flags_KF0 |= 0x1;
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
token.flags = state.flags_KB0;
do{
token.sub_kind = TokenOdinKind_Plus;
token.kind = 7;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_KF0 |= 0x1;
state.flags_ZF0 = 0;
goto state_label_1; // root
}break;
case 0x3d:
{
state.ptr += 1;
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
token.flags = state.flags_KB0;
do{
token.sub_kind = TokenOdinKind_PlusEq;
token.kind = 7;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_KF0 |= 0x1;
state.flags_ZF0 = 0;
goto state_label_1; // root
}break;
}
}
{
state_label_36: // op stage
if (state.ptr == state.opl_ptr){
if ((true)){
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
token.flags = state.flags_KB0;
do{
token.sub_kind = TokenOdinKind_Minus;
token.kind = 7;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
}
state.flags_KF0 |= 0x1;
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
token.flags = state.flags_KB0;
do{
token.sub_kind = TokenOdinKind_Minus;
token.kind = 7;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_KF0 |= 0x1;
state.flags_ZF0 = 0;
goto state_label_1; // root
}break;
case 0x3d:
{
state.ptr += 1;
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
token.flags = state.flags_KB0;
do{
token.sub_kind = TokenOdinKind_MinusEq;
token.kind = 7;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_KF0 |= 0x1;
state.flags_ZF0 = 0;
goto state_label_1; // root
}break;
}
}
{
state_label_37: // op stage
if (state.ptr == state.opl_ptr){
if ((true)){
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
token.flags = state.flags_KB0;
do{
token.sub_kind = TokenOdinKind_Star;
token.kind = 7;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
}
state.flags_KF0 |= 0x1;
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
token.flags = state.flags_KB0;
do{
token.sub_kind = TokenOdinKind_Star;
token.kind = 7;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_KF0 |= 0x1;
state.flags_ZF0 = 0;
goto state_label_1; // root
}break;
case 0x3d:
{
state.ptr += 1;
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
token.flags = state.flags_KB0;
do{
token.sub_kind = TokenOdinKind_StarEq;
token.kind = 7;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_KF0 |= 0x1;
state.flags_ZF0 = 0;
goto state_label_1; // root
}break;
}
}
{
state_label_38: // op stage
if (state.ptr == state.opl_ptr){
if ((true)){
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
token.flags = state.flags_KB0;
do{
token.sub_kind = TokenOdinKind_Mod;
token.kind = 7;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
}
state.flags_KF0 |= 0x1;
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
token.flags = state.flags_KB0;
do{
token.sub_kind = TokenOdinKind_Mod;
token.kind = 7;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_KF0 |= 0x1;
state.flags_ZF0 = 0;
goto state_label_1; // root
}break;
case 0x3d:
{
state.ptr += 1;
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
token.flags = state.flags_KB0;
do{
token.sub_kind = TokenOdinKind_ModEq;
token.kind = 7;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_KF0 |= 0x1;
state.flags_ZF0 = 0;
goto state_label_1; // root
}break;
}
}
{
state_label_39: // op stage
if (state.ptr == state.opl_ptr){
if ((true)){
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
token.flags = state.flags_KB0;
do{
token.sub_kind = TokenOdinKind_LeftLeft;
token.kind = 7;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
}
state.flags_KF0 |= 0x1;
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
token.flags = state.flags_KB0;
do{
token.sub_kind = TokenOdinKind_LeftLeft;
token.kind = 7;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_KF0 |= 0x1;
state.flags_ZF0 = 0;
goto state_label_1; // root
}break;
case 0x3d:
{
state.ptr += 1;
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
token.flags = state.flags_KB0;
do{
token.sub_kind = TokenOdinKind_LeftLeftEq;
token.kind = 7;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_KF0 |= 0x1;
state.flags_ZF0 = 0;
goto state_label_1; // root
}break;
}
}
{
state_label_40: // op stage
if (state.ptr == state.opl_ptr){
if ((true)){
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
token.flags = state.flags_KB0;
do{
token.sub_kind = TokenOdinKind_RightRight;
token.kind = 7;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
}
state.flags_KF0 |= 0x1;
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
token.flags = state.flags_KB0;
do{
token.sub_kind = TokenOdinKind_RightRight;
token.kind = 7;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_KF0 |= 0x1;
state.flags_ZF0 = 0;
goto state_label_1; // root
}break;
case 0x3d:
{
state.ptr += 1;
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
token.flags = state.flags_KB0;
do{
token.sub_kind = TokenOdinKind_RightRightEq;
token.kind = 7;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_KF0 |= 0x1;
state.flags_ZF0 = 0;
goto state_label_1; // root
}break;
}
}
{
state_label_41: // op stage
if (state.ptr == state.opl_ptr){
if ((true)){
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
token.flags = state.flags_KB0;
do{
token.sub_kind = TokenOdinKind_DotDot;
token.kind = 7;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
}
state.flags_KF0 |= 0x1;
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
token.flags = state.flags_KB0;
do{
token.sub_kind = TokenOdinKind_DotDot;
token.kind = 7;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_KF0 |= 0x1;
state.flags_ZF0 = 0;
goto state_label_1; // root
}break;
case 0x3c:
{
state.ptr += 1;
{
Token token = {};
token.pos = (i64)(state.emit_ptr - state.base);
token.size = (i64)(state.ptr - state.emit_ptr);
token.flags = state.flags_KB0;
do{
token.sub_kind = TokenOdinKind_DotDotLess;
token.kind = 7;
}while(0);
token_list_push(arena, list, &token);
emit_counter += 1;
state.emit_ptr = state.ptr;
if (emit_counter == max){
goto end;
}
}
state.flags_KF0 |= 0x1;
state.flags_ZF0 = 0;
goto state_label_1; // root
}break;
}
}
end:;
block_copy_struct(state_ptr, &state);
return(result);
}
internal Token_List
lex_full_input_odin(Arena *arena, String_Const_u8 input){
Lex_State_Odin state = {};
lex_full_input_odin_init(&state, input);
Token_List list = {};
lex_full_input_odin_breaks(arena, &list, &state, max_u64);
return(list);
}
