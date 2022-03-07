__m128i ABCD_SAVE, MASK, E0, E0_SAVE, E1, MSG0, MSG1, MSG2, MSG3;
                        MASK = _mm_set_epi8(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);
                        E0 = _mm_set_epi32(*((int*)&acceptBytes[16]), 0, 0, 0);
                        int ptr = -16;
                        while ((j -= 64) >= i)
                        {
                            ABCD_SAVE = *((__m128i*)acceptBytes);
                            E0_SAVE = E0;

                            MSG0 = _mm_shuffle_epi8(*((__m128i*) & ((char*)peer->receiveBuffer)[i + (ptr += 16)]), MASK);
                            E0 = _mm_add_epi32(E0, MSG0);
                            E1 = *((__m128i*)acceptBytes);
                            *((__m128i*)acceptBytes) = _mm_sha1rnds4_epu32(*((__m128i*)acceptBytes), E0, 0);

                            MSG1 = _mm_shuffle_epi8(*((__m128i*) & ((char*)peer->receiveBuffer)[i + (ptr += 16)]), MASK);
                            E1 = _mm_sha1nexte_epu32(E1, MSG1);
                            E0 = *((__m128i*)acceptBytes);
                            *((__m128i*)acceptBytes) = _mm_sha1rnds4_epu32(*((__m128i*)acceptBytes), E1, 0);
                            MSG0 = _mm_sha1msg1_epu32(MSG0, MSG1);

                            MSG2 = _mm_shuffle_epi8(*((__m128i*) & ((char*)peer->receiveBuffer)[i + (ptr += 16)]), MASK);
                            E0 = _mm_sha1nexte_epu32(E0, MSG2);
                            E1 = *((__m128i*)acceptBytes);
                            *((__m128i*)acceptBytes) = _mm_sha1rnds4_epu32(*((__m128i*)acceptBytes), E0, 0);
                            MSG1 = _mm_sha1msg1_epu32(MSG1, MSG2);
                            MSG0 = _mm_xor_si128(MSG0, MSG2);

                            MSG3 = _mm_shuffle_epi8(*((__m128i*) & ((char*)peer->receiveBuffer)[i + (ptr += 16)]), MASK);
                            E1 = _mm_sha1nexte_epu32(E1, MSG3);
                            E0 = *((__m128i*)acceptBytes);
                            MSG0 = _mm_sha1msg2_epu32(MSG0, MSG3);
                            *((__m128i*)acceptBytes) = _mm_sha1rnds4_epu32(*((__m128i*)acceptBytes), E1, 0);
                            MSG2 = _mm_sha1msg1_epu32(MSG2, MSG3);
                            MSG1 = _mm_xor_si128(MSG1, MSG3);

                            E0 = _mm_sha1nexte_epu32(E0, MSG0);
                            E1 = *((__m128i*)acceptBytes);
                            MSG1 = _mm_sha1msg2_epu32(MSG1, MSG0);
                            *((__m128i*)acceptBytes) = _mm_sha1rnds4_epu32(*((__m128i*)acceptBytes), E0, 0);
                            MSG3 = _mm_sha1msg1_epu32(MSG3, MSG0);
                            MSG2 = _mm_xor_si128(MSG2, MSG0);

                            E1 = _mm_sha1nexte_epu32(E1, MSG1);
                            E0 = *((__m128i*)acceptBytes);
                            MSG2 = _mm_sha1msg2_epu32(MSG2, MSG1);
                            *((__m128i*)acceptBytes) = _mm_sha1rnds4_epu32(*((__m128i*)acceptBytes), E1, 1);
                            MSG0 = _mm_sha1msg1_epu32(MSG0, MSG1);
                            MSG3 = _mm_xor_si128(MSG3, MSG1);

                            E0 = _mm_sha1nexte_epu32(E0, MSG2);
                            E1 = *((__m128i*)acceptBytes);
                            MSG3 = _mm_sha1msg2_epu32(MSG3, MSG2);
                            *((__m128i*)acceptBytes) = _mm_sha1rnds4_epu32(*((__m128i*)acceptBytes), E0, 1);
                            MSG1 = _mm_sha1msg1_epu32(MSG1, MSG2);
                            MSG0 = _mm_xor_si128(MSG0, MSG2);

                            E1 = _mm_sha1nexte_epu32(E1, MSG3);
                            E0 = *((__m128i*)acceptBytes);
                            MSG0 = _mm_sha1msg2_epu32(MSG0, MSG3);
                            *((__m128i*)acceptBytes) = _mm_sha1rnds4_epu32(*((__m128i*)acceptBytes), E1, 1);
                            MSG2 = _mm_sha1msg1_epu32(MSG2, MSG3);
                            MSG1 = _mm_xor_si128(MSG1, MSG3);

                            E0 = _mm_sha1nexte_epu32(E0, MSG0);
                            E1 = *((__m128i*)acceptBytes);
                            MSG1 = _mm_sha1msg2_epu32(MSG1, MSG0);
                            *((__m128i*)acceptBytes) = _mm_sha1rnds4_epu32(*((__m128i*)acceptBytes), E0, 1);
                            MSG3 = _mm_sha1msg1_epu32(MSG3, MSG0);
                            MSG2 = _mm_xor_si128(MSG2, MSG0);

                            E1 = _mm_sha1nexte_epu32(E1, MSG1);
                            E0 = *((__m128i*)acceptBytes);
                            MSG2 = _mm_sha1msg2_epu32(MSG2, MSG1);
                            *((__m128i*)acceptBytes) = _mm_sha1rnds4_epu32(*((__m128i*)acceptBytes), E1, 1);
                            MSG0 = _mm_sha1msg1_epu32(MSG0, MSG1);
                            MSG3 = _mm_xor_si128(MSG3, MSG1);

                            E0 = _mm_sha1nexte_epu32(E0, MSG2);
                            E1 = *((__m128i*)acceptBytes);
                            MSG3 = _mm_sha1msg2_epu32(MSG3, MSG2);
                            *((__m128i*)acceptBytes) = _mm_sha1rnds4_epu32(*((__m128i*)acceptBytes), E0, 2);
                            MSG1 = _mm_sha1msg1_epu32(MSG1, MSG2);
                            MSG0 = _mm_xor_si128(MSG0, MSG2);

                            E1 = _mm_sha1nexte_epu32(E1, MSG3);
                            E0 = *((__m128i*)acceptBytes);
                            MSG0 = _mm_sha1msg2_epu32(MSG0, MSG3);
                            *((__m128i*)acceptBytes) = _mm_sha1rnds4_epu32(*((__m128i*)acceptBytes), E1, 2);
                            MSG2 = _mm_sha1msg1_epu32(MSG2, MSG3);
                            MSG1 = _mm_xor_si128(MSG1, MSG3);

                            E0 = _mm_sha1nexte_epu32(E0, MSG0);
                            E1 = *((__m128i*)acceptBytes);
                            MSG1 = _mm_sha1msg2_epu32(MSG1, MSG0);
                            *((__m128i*)acceptBytes) = _mm_sha1rnds4_epu32(*((__m128i*)acceptBytes), E0, 2);
                            MSG3 = _mm_sha1msg1_epu32(MSG3, MSG0);
                            MSG2 = _mm_xor_si128(MSG2, MSG0);

                            E1 = _mm_sha1nexte_epu32(E1, MSG1);
                            E0 = *((__m128i*)acceptBytes);
                            MSG2 = _mm_sha1msg2_epu32(MSG2, MSG1);
                            *((__m128i*)acceptBytes) = _mm_sha1rnds4_epu32(*((__m128i*)acceptBytes), E1, 2);
                            MSG0 = _mm_sha1msg1_epu32(MSG0, MSG1);
                            MSG3 = _mm_xor_si128(MSG3, MSG1);

                            E0 = _mm_sha1nexte_epu32(E0, MSG2);
                            E1 = *((__m128i*)acceptBytes);
                            MSG3 = _mm_sha1msg2_epu32(MSG3, MSG2);
                            *((__m128i*)acceptBytes) = _mm_sha1rnds4_epu32(*((__m128i*)acceptBytes), E0, 2);
                            MSG1 = _mm_sha1msg1_epu32(MSG1, MSG2);
                            MSG0 = _mm_xor_si128(MSG0, MSG2);

                            E1 = _mm_sha1nexte_epu32(E1, MSG3);
                            E0 = *((__m128i*)acceptBytes);
                            MSG0 = _mm_sha1msg2_epu32(MSG0, MSG3);
                            *((__m128i*)acceptBytes) = _mm_sha1rnds4_epu32(*((__m128i*)acceptBytes), E1, 3);
                            MSG2 = _mm_sha1msg1_epu32(MSG2, MSG3);
                            MSG1 = _mm_xor_si128(MSG1, MSG3);

                            E0 = _mm_sha1nexte_epu32(E0, MSG0);
                            E1 = *((__m128i*)acceptBytes);
                            MSG1 = _mm_sha1msg2_epu32(MSG1, MSG0);
                            *((__m128i*)acceptBytes) = _mm_sha1rnds4_epu32(*((__m128i*)acceptBytes), E0, 3);
                            MSG3 = _mm_sha1msg1_epu32(MSG3, MSG0);
                            MSG2 = _mm_xor_si128(MSG2, MSG0);

                            E1 = _mm_sha1nexte_epu32(E1, MSG1);
                            E0 = *((__m128i*)acceptBytes);
                            MSG2 = _mm_sha1msg2_epu32(MSG2, MSG1);
                            *((__m128i*)acceptBytes) = _mm_sha1rnds4_epu32(*((__m128i*)acceptBytes), E1, 3);
                            MSG3 = _mm_xor_si128(MSG3, MSG1);

                            E0 = _mm_sha1nexte_epu32(E0, MSG2);
                            E1 = *((__m128i*)acceptBytes);
                            MSG3 = _mm_sha1msg2_epu32(MSG3, MSG2);
                            *((__m128i*)acceptBytes) = _mm_sha1rnds4_epu32(*((__m128i*)acceptBytes), E0, 3);

                            E1 = _mm_sha1nexte_epu32(E1, MSG3);
                            E0 = *((__m128i*)acceptBytes);
                            *((__m128i*)acceptBytes) = _mm_sha1rnds4_epu32(*((__m128i*)acceptBytes), E1, 3);

                            E0 = _mm_sha1nexte_epu32(E0, E0_SAVE);
                            *((__m128i*)acceptBytes) = _mm_add_epi32(*((__m128i*)acceptBytes), ABCD_SAVE);
                        }
