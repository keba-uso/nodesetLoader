/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 *    Copyright 2019 (c) Matthias Konnerth
 */

#include "backend.h"

int addNamespace(void *userContext, const char *uri) { return 1; }

void dumpNode(void *userContext, const NL_Node *node)
{
    printf("NodeId: %s BrowseName: %s DisplayName: %s\n", node->id.id,
           node->browseName.name, node->displayName.text);

    switch (node->nodeClass)
    {
    case NODECLASS_OBJECT:
        printf("\tparentNodeId: %s\n",
               ((const NL_ObjectNode *)node)->parentNodeId.id);
        printf("\teventNotifier: %s\n",
               ((const NL_ObjectNode *)node)->eventNotifier);
        break;
    case NODECLASS_VARIABLE:
        printf("\tparentNodeId: %s\n",
               ((const NL_VariableNode *)node)->parentNodeId.id);
        printf("\tdatatype: %s\n", ((const NL_VariableNode *)node)->datatype.id);
        printf("\tvalueRank: %s\n", ((const NL_VariableNode *)node)->valueRank);
        printf("\tarrayDimensions: %s\n",
               ((const NL_VariableNode *)node)->valueRank);
        break;
    case NODECLASS_OBJECTTYPE:
        break;
    case NODECLASS_DATATYPE:
        break;
    case NODECLASS_METHOD:
        break;
    case NODECLASS_REFERENCETYPE:
    case NODECLASS_VARIABLETYPE:
        break;
    }
    NL_Reference *hierachicalRef = node->hierachicalRefs;
    while (hierachicalRef)
    {
        printf("\treftype: %s target: %s\n", hierachicalRef->refType.id,
               hierachicalRef->target.id);
        hierachicalRef = hierachicalRef->next;
    }

    NL_Reference *nonHierRef = node->nonHierachicalRefs;
    while (nonHierRef)
    {
        printf("\treftype: %s target: %s\n", nonHierRef->refType.id,
               nonHierRef->target.id);
        nonHierRef = nonHierRef->next;
    }
}