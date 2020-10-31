using System.Collections;
using UnityEngine;
using UnityEngine.SceneManagement;



public class GlobalControl : MonoBehaviour
{
    public Camera _cam;
    public Transform _prefab;
    public Stats stats;
    private void Start()
    {
        StartCoroutine(CleanScren());        
        stats.endGame = false;
    }
    private void Update()
    {
        if (Input.GetMouseButtonDown(0))
        {            
            Instantiate(_prefab, _cam.ScreenToWorldPoint(Input.mousePosition), _prefab.rotation);  
        }

        if (stats.endGame)
        {
            SceneManager.LoadScene("EndGame_scene");
        }
    }

    IEnumerator CleanScren()
    {
        while (true)
        {
           yield return new WaitForSeconds(0.1f);             
           Destroy(GameObject.Find("Collider(Clone)"));
        }        
    }   
}
