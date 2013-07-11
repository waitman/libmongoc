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


#ifndef MONGOC_CLUSTER_PRIVATE_H
#define MONGOC_CLUSTER_PRIVATE_H


#include <bson/bson.h>

#include "mongoc-array-private.h"
#include "mongoc-buffer-private.h"
#include "mongoc-host-list.h"
#include "mongoc-read-prefs.h"
#include "mongoc-rpc-private.h"
#include "mongoc-stream.h"
#include "mongoc-uri.h"
#include "mongoc-write-concern.h"


BSON_BEGIN_DECLS


#define MONGOC_CLUSTER_MAX_NODES 12


typedef enum
{
   MONGOC_CLUSTER_DIRECT,
   MONGOC_CLUSTER_REPLICA_SET,
   MONGOC_CLUSTER_SHARDED_CLUSTER,
} mongoc_cluster_mode_t;


typedef enum
{
   MONGOC_CLUSTER_STATE_BORN      = 0,
   MONGOC_CLUSTER_STATE_HEALTHY   = 1,
   MONGOC_CLUSTER_STATE_DEAD      = 2,
   MONGOC_CLUSTER_STATE_UNHEALTHY = (MONGOC_CLUSTER_STATE_DEAD |
                                     MONGOC_CLUSTER_STATE_HEALTHY),
} mongoc_cluster_state_t;


typedef struct
{
   bson_uint32_t       index;
   mongoc_host_list_t  host;
   mongoc_stream_t    *stream;
   bson_bool_t         primary;
   bson_int32_t        ping_msec;
   bson_uint32_t       stamp;
   bson_t              tags;
} mongoc_cluster_node_t;


typedef struct
{
   mongoc_cluster_mode_t   mode;
   mongoc_cluster_state_t  state;

   bson_uint32_t           request_id;

   mongoc_uri_t           *uri;
   mongoc_cluster_node_t   nodes[MONGOC_CLUSTER_MAX_NODES];
   void                   *client;
   bson_uint32_t           max_bson_size;
   bson_uint32_t           max_msg_size;
   bson_uint32_t           sec_latency_ms;
   mongoc_array_t          iov;
} mongoc_cluster_t;


void          mongoc_cluster_destroy      (mongoc_cluster_t       *cluster);
void          mongoc_cluster_init         (mongoc_cluster_t       *cluster,
                                           const mongoc_uri_t     *uri,
                                           void                   *client);
bson_uint32_t mongoc_cluster_sendv        (mongoc_cluster_t       *cluster,
                                           mongoc_rpc_t           *rpcs,
                                           size_t                  rpcs_len,
                                           bson_uint32_t           hint,
                                           mongoc_write_concern_t *write_concern,
                                           mongoc_read_prefs_t    *read_prefs,
                                           bson_error_t           *error);
bson_uint32_t mongoc_cluster_try_sendv    (mongoc_cluster_t       *cluster,
                                           mongoc_rpc_t           *rpcs,
                                           size_t                  rpcs_len,
                                           bson_uint32_t           hint,
                                           mongoc_write_concern_t *write_concern,
                                           mongoc_read_prefs_t    *read_prefs,
                                           bson_error_t           *error);
bson_bool_t   mongoc_cluster_try_recv     (mongoc_cluster_t       *cluster,
                                           mongoc_rpc_t           *rpc,
                                           mongoc_buffer_t        *buffer,
                                           bson_uint32_t           hint,
                                           bson_error_t           *error);
bson_uint32_t mongoc_cluster_stamp        (mongoc_cluster_t       *cluster,
                                           bson_uint32_t           node);
bson_bool_t   mongoc_cluster_getlasterror (mongoc_cluster_t       *cluster,
                                           bson_uint32_t           hint,
                                           const char             *database,
                                           const bson_t           *options,
                                           bson_t                 *result,
                                           bson_error_t           *error);


BSON_END_DECLS


#endif /* MONGOC_CLUSTER_PRIVATE_H */
