/**
 * Copyright (c) 2011-2015 libbitcoin developers (see AUTHORS)
 *
 * This file is part of libbitcoin.
 *
 * libbitcoin is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License with
 * additional permissions to the one published by the Free Software
 * Foundation, either version 3 of the License, or (at your option)
 * any later version. For more information see LICENSE.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Affero General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */
#include <bitcoin/bitcoin/math/crypto.hpp>

#include <bitcoin/bitcoin/math/ec_keys.hpp>
#include <bitcoin/bitcoin/math/hash.hpp>
#include <bitcoin/bitcoin/utility/assert.hpp>
#include <bitcoin/bitcoin/utility/data.hpp>
#include "../math/external/aes256.h"

namespace libbitcoin {

void aes256_encrypt(const aes_secret& key, aes_block& block)
{
    aes256_context context;
    aes256_init(&context, key.data());
    aes256_encrypt_ecb(&context, block.data());
    aes256_done(&context);
}

void aes256_decrypt(const aes_secret& key, aes_block& block)
{
    aes256_context context;
    aes256_init(&context, key.data());
    aes256_decrypt_ecb(&context, block.data());
    aes256_done(&context);
}

// DEPRECATED
void aes256_encrypt(data_slice key, data_chunk& block)
{
    BITCOIN_ASSERT(key.size() == aes256_key_size);
    BITCOIN_ASSERT(block.size() == aes256_block_size);

    aes256_context context;
    aes256_init(&context, key.data());
    aes256_encrypt_ecb(&context, block.data());
    aes256_done(&context);
}

// DEPRECATED
void aes256_decrypt(data_slice key, data_chunk& block)
{
    BITCOIN_ASSERT(key.size() == aes256_key_size);
    BITCOIN_ASSERT(block.size() == aes256_block_size);

    aes256_context context;
    aes256_init(&context, key.data());
    aes256_decrypt_ecb(&context, block.data());
    aes256_done(&context);
}

} // namespace libbitcoin
