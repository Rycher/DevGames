using System;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.Rendering;
using UnityEngine.SceneManagement;



public class ButtonManager : MonoBehaviour

{
    public Stats stats;
    public void MoveScene()
    {
        if (stats.lastMap == 2)
        {
            SceneManager.LoadScene("Game_scene_2");
        }
        else
        {
            SceneManager.LoadScene("Game_scene");
        }

    } 

    public void ExitGame()
    {        
        Application.Quit();
    }

    public void MenuGame()
    {
        SceneManager.LoadScene("Menu_scene");
        stats.lastMap = 1;
    }

    public void NextLevel()
    {
        SceneManager.LoadScene("Game_scene_2");
    }

    public void Credits()
    {
        SceneManager.LoadScene("Credits_scene");
    }
}
