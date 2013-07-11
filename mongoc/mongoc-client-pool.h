/*
 * Copyright 2013 10gen Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */


#ifndef MONGOC_CLIENT_POOL_H
#define MONGOC_CLIENT_POOL_H


#include <bson/bson.h>

#include "mongoc-client.h"
#include "mongoc-uri.h"


BSON_BEGIN_DECLS


typedef struct _mongoc_client_pool_t mongoc_client_pool_t;


mongoc_client_pool_t *mongoc_client_pool_new     (const mongoc_uri_t *uri);
void                  mongoc_client_pool_destroy (mongoc_client_pool_t *pool);
mongoc_client_t      *mongoc_client_pool_pop     (mongoc_client_pool_t *pool);
void                  mongoc_client_pool_push    (mongoc_client_pool_t *pool,
                                                  mongoc_client_t      *client);


BSON_END_DECLS


#endif /* MONGOC_CLIENT_POOL_H */
