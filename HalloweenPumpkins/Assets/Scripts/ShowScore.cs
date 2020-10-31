using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
using UnityEngine.SceneManagement;


public class ShowScore : MonoBehaviour
{
    private Text _score;
    public Stats stats;

    private void Start()
    {
        _score = this.GetComponent<Text>();
        if (!SceneManager.GetSceneByName("EndGame_scene").isLoaded)
            stats.score = 0;
    }

    void Update()
    {
        if (SceneManager.GetSceneByName("Game_scene").isLoaded)
        {
            stats.lastMap = 1;
            _score.text = "Score: " + stats.score + "/1500";
        }
        else if (SceneManager.GetSceneByName("Game_scene_2").isLoaded)
        {
            stats.lastMap = 2;
            _score.text = "Score: " + stats.score + "/2000";            
        }


        if (SceneManager.GetSceneByName("EndGame_scene").isLoaded && stats.lastMap == 1)
        {
            _score.text = "Score: " + stats.score + "/1500";
            if (stats.score < 1500)
            {
               GameObject button = GameObject.Find("Button (3)");
                button.SetActive(false); 
            }
        }
        else if (SceneManager.GetSceneByName("EndGame_scene").isLoaded && stats.lastMap == 2)
        {
            _score.text = "Score: " + stats.score + "/2000";
            if (stats.score < 2000)
            {
                GameObject button = GameObject.Find("Button (3)");
                button.SetActive(false);               
            }
            else
            {
                SceneManager.LoadScene("Credits_scene");
            }
        }

    }
}
