#include "Projection.h"
#include <cmath>

Vector2 project(Vector3 point, float aspectRatio) {
    float theta = 90*(M_PI/180); // FOV
    float projectionScale = tan(theta/2);
    
    Vector2 result;

    /*
        Antag view plane er på z = 1
        Forestil en retvinklet trekant mellem kamera og point.
        Den retvinklede trekant og view plane har parrelel side på x-aksen.
        Vi skal finde punktet på view plane hvor den retvinklede trekants hypotenuse skærer.
        Altså punktet på view plane hvor point skal placeres. Lad os kalde den viewX
        Trekant XYHyp og ViewplaneViewXHyp er ligedannede. Vi kan derfor beregne:
        tan(theta/2)=x/z
        tan(theta/2)=viewX/viewPlane
        Hvor theta er kameraets FOV. Vi kan løse dette som en ligning med 2 ubekente:
        tan(theta/2)=x/z=viewX/viewPlane => tan(theta/2) er irrelavant
        x/z=viewX/viewPlane => x/z*viewPlane=viewX => Da viewplane er 1 kan vi simplificere til viewX=x/z
        Nu ved vi at point skærer viewplane på x/z.
        For at putte x/z ind på en skala mellem 0 og 1 (eller -1 hvis x er negativ),
        skal vi bare kende grundlinjen på vores viewplane (hvis man tænker det som en trekant mellem viewplane og kamera).
        Vi kan igen lave trigonometri med tangens:
        tan(theta/2)=grundlinje/viewplane => tan(theta/2)=grundlinje/1
        Så grundlinjen er bare tan(theta/2). Husk det er halve theta fordi vi bruger retvinklede trekanter langs-z aksen,
        og derfor skærer vores FOV over i 2.
        Nu kan vi samle det hele:
        skaleretX=(x/z)/tan(theta/2)
    */
    result.x = (point.x / point.z) / (projectionScale * aspectRatio);
    result.y = (point.y / point.z) / projectionScale;
    
    return result;
}