using System;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class Stats_Enemy : MonoBehaviour
{
    private Rigidbody2D rb;
    public Stats stats;
    public int score;
    void Start()
    {
        rb = this.GetComponent<Rigidbody2D>();
        rb.AddForce(transform.up * 12, ForceMode2D.Impulse);
    }

    private void OnTriggerStay2D(Collider2D collision)
    {
        if (collision.gameObject.name == "Collider(Clone)")
        {
            Destroy(this.gameObject);            
            stats.score += score;            
        }

        if (collision.gameObject.name == "EndGame")
        {            
            stats.endGame = true;
        }
        
    }

    private void OnTriggerEnter2D(Collider2D collision)
    {
        if (collision.gameObject.name == "Collider(Clone)")
        {
            Destroy(this.gameObject);
            stats.score += score;
        }

        if (collision.gameObject.name == "EndGame")
        {
            stats.endGame = true;
        }

    }

    private void OnTriggerExit2D(Collider2D collision)
    {
        if (collision.gameObject.name == "Collider(Clone)")
        {
            Destroy(this.gameObject);
            stats.score += score;
        }

        if (collision.gameObject.name == "EndGame")
        {
            stats.endGame = true;
        }

    }
}
