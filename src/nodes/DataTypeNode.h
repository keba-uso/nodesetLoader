/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 *    Copyright 2020 (c) Matthias Konnerth
 */

#ifndef DATATYPENODE_H
#define DATATYPENODE_H
#include <NodesetLoader/NodesetLoader.h>

void DataTypeNode_clear(NL_DataTypeNode *node);
NL_DataTypeDefinition *DataTypeDefinition_new(NL_DataTypeNode *node);
NL_DataTypeDefinitionField *DataTypeNode_addDefinitionField(NL_DataTypeDefinition *def);
#endif
