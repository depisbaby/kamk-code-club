using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class CellGrid : MonoBehaviour
{
    public static CellGrid Instance;
    private void Awake()
    {
        Instance = this;
    }

    public class Cell
    {
        public int xPosition;
        public int yPosition;
        public SpriteRenderer sr;
    }

    Cell[,] cells;

    [SerializeField] GameObject cellPrefab;
    [SerializeField] Texture2D input;

    private void Start()
    {
        InitializeGrid(0.15f);
    }

    public void InitializeGrid(float cellDiameter)
    {
        int xSize = input.width;
        int ySize = input.height;

        cells = new Cell[xSize, ySize];

        for (int y = 0; y < ySize; y++)
        {
            for (int x = 0; x < xSize; x++)
            {
                cells[x, y] = new Cell();
                cells[x, y].xPosition = x;
                cells[x, y].yPosition = y;
                GameObject go = Instantiate(cellPrefab);
                go.transform.position = transform.position + new Vector3(x * cellDiameter, y * cellDiameter, 0);
                cells[x,y].sr = go.GetComponent<SpriteRenderer>();
                SetCellFromInput(cells[x, y]);
            }
        }
    }

    public void SetColor(int x, int y, Color color)
    {
        cells[x,y].sr.color = color;
    }

    void SetCellFromInput(Cell cell)
    {

        Debug.Log(cell.xPosition + ", " + cell.yPosition);
        Color color = input.GetPixel(cell.xPosition, cell.yPosition);

        if(color.r == 0f && color.g == 0f && color.b == 0f) //pixel is black
        { 

            SetColor(cell.xPosition, cell.yPosition, Color.black);
        }
        else if (color.r == 1f && color.g == 1f && color.b == 1f) //pixel is white
        {

            SetColor(cell.xPosition, cell.yPosition, Color.white);
        }
        else if(color.r < 0.5f && color.g < 0.5f && color.b > 0.5f) //pixel is blue
        {

            SetColor(cell.xPosition, cell.yPosition, Color.blue);
        }
        else //pixel is other color
        {

            SetColor(cell.xPosition, cell.yPosition, Color.green);
        }
    }
}
