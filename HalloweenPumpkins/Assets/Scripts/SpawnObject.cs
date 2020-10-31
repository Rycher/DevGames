using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class SpawnObject : MonoBehaviour
{
    public GameObject _object;
    public Transform[] _spawnPoints;
    public float _minDelay;
    public float _maxDelay;

    private void Start()
    {
        StartCoroutine(SpawnObjects());
    }

    IEnumerator SpawnObjects()
    {
        while(true)
        {
            float _delay = Random.Range(_minDelay, _maxDelay);
            yield return new WaitForSeconds(_delay);

            int spawnIndex = Random.Range(0, _spawnPoints.Length);

            Transform spawnPoint = _spawnPoints[spawnIndex];

            Instantiate(_object, spawnPoint.position, spawnPoint.rotation);
        }
    }
}
