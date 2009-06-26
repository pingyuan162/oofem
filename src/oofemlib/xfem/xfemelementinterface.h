#ifndef xfemelementinterface_h
#define xfemelementinterface_h

#include "interface.h"
#include "gausspnt.h"
#include "xfemmanager.h"
#include "matresponsemode.h"
#include "structuralelement.h"

/** provides xfem interface for an element */
class XfemElementInterface : public Interface
{
public:
    /// constructor
    XfemElementInterface(Element *e) : Interface() { this->element = e; }
    /// creates enriched part of B matrix
    void XfemElementInterface_createEnrBmatrixAt(GaussPoint *gp, FloatMatrix &answer);
    /// partitions the element into patches by a triangulation
    void XfemElementInterface_partitionElement(AList< Triangle > *answer, AList< FloatArray > *together);
    /// updates integration rule based on the triangulation
    void XfemElementInterface_updateIntegrationRule();
    /// helpful routine to put the nodes for triangulation together, should be in protected members probably
    void XfemElementInterface_prepareNodesForDelaunay(AList< FloatArray > *answer1, AList< FloatArray > *answer2);
protected:
    Element *element;
};
#endif