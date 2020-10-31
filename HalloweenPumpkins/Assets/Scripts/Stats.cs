using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

[CreateAssetMenu(fileName = "score", menuName = "score")]
public class Stats : ScriptableObject
{
    public int score;
    public bool endGame;
    public int lastMap;
}    
    
