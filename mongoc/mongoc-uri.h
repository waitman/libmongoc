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


#ifndef MONGOC_URI_H
#define MONGOC_URI_H


#include <bson/bson.h>

#include "mongoc-host-list.h"


BSON_BEGIN_DECLS


typedef struct _mongoc_uri_t mongoc_uri_t;


mongoc_uri_t             *mongoc_uri_copy                 (const mongoc_uri_t *uri);
void                      mongoc_uri_destroy              (mongoc_uri_t       *uri);
mongoc_uri_t             *mongoc_uri_new                  (const char         *uri_string);
const mongoc_host_list_t *mongoc_uri_get_hosts            (const mongoc_uri_t *uri);
const char               *mongoc_uri_get_database         (const mongoc_uri_t *uri);
const bson_t             *mongoc_uri_get_options          (const mongoc_uri_t *uri);
const char               *mongoc_uri_get_string           (const mongoc_uri_t *uri);
const bson_t             *mongoc_uri_get_read_preferences (const mongoc_uri_t *uri);


BSON_END_DECLS


#endif /* MONGOC_URI_H */
