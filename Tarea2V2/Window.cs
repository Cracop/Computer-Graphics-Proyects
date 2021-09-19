using OpenTK.Graphics.OpenGL4;
using OpenTK.Windowing.Common;
using OpenTK.Windowing.GraphicsLibraryFramework;
using OpenTK.Windowing.Desktop;
//Rodrigo Barrera 181935
namespace Tarea2V2{
    public class Window : GameWindow {
        float[] _vertices = {
            0.0f, 0.2f, 0.0f,//0

            -0.027f,0.1f,0.0f,//1
            0.027f,0.1f,0.0f,//2
            0.1f, 0.1723f,0.0f,//3

            0.07814f, 0.0714f,0.0f,//4
            0.2f, 0.0f, 0.0f,//5
            0.1f,-0.027f,0.0f,//6

            0.1f,0.027f,0.0f,//7
            0.173f,0.1f,0.0f,//8
            0.0745f, 0.272f,0.0f,//9

            0.2005f,0.195f,0.0f, //10
            0.273f,0.074f,0.0f,//11
            0.0f, 0.35f,0.0f,//12

            0.35f,0.0f,0.0f,//13
            0.175f,0.295f,0.0f,//14
            0.2973f,0.1739f,0.0f,//15

            0.106f,0.371f,0.0f,//16
            0.275f,0.27f,0.0f,//17
            0.3735f,0.104f,0.0f,//18

            0.027f, 0.45f,0.0f,//19
            -0.027f, 0.45f,0.0f,//20
            0.0f,0.55f,0.0f,//21

            0.0f,0.604f,0.0f,//22
            0.1f,0.577f,0.0f,//23
            0.45f,0.027f,0.0f,//24

            0.45f,-0.027f,0.0f,//25
            0.55f,0.0f,0.0f,//26
            0.604f,0.0f,0.0f,//27

            0.577f,0.1f,0.0f,//28
            0.1981f,0.3951f,0.0f,//29
            0.s2492f, 0.3665f,0.0f,//30

            0.2711f,0.4674f,0.0f,//31
            0.378f,0.2316f,0.0f,//32
            0.3998f,0.1872f,0.0f,//33

            0.4728f, 0.2602f, 0.0f,//34
            0.1293f,0.4712f,0.0f,//35
            0.3495f,0.3418f,0.0f,//36

            0.4758f,0.1174f,0.0f,//37
            0.2023f, 0.5437f,0.0f,//38
            0.37135f,0.44275f,0.0f,//39

            0.462f,0.3588f,0.0f,//40
            0.54885f, 0.1904f, 0.0f,//41
            0.1775f,0.6435f,0.0f,//42
            
            0.47f,0.472f,0.0f,//43
            0.6462f,0.1554f,0.0f,//44
            0.08f,0.675f,0.0f,//45

            0.278f,0.616f,0.0f,//46
            0.4012f,0.5627f,0.0f,//47
            0.5638f,0.4288f,0.0f,//48

            0.6206f,0.2459f,0.0f,//49
            0.6445f,0.052f,0.0f,//50
            0.0f,0.0f,0.0f,//51

            0.3008f,0.5144f,0.0f,//52
            0.52f,0.29f,0.0f,//53,
            0.0f,0.675f,0.0f,//54

            0.6445f,0.0f,0.0f,//55
            0.0f,0.746f,0.0f,//56
            0.368f,0.669f,0.0f,//57

            0.6644f,0.4052f,0.0f,//58
            0.685f,0.0f,0.0f,//59
            0.027f,0.846f,0.0f,//60

            -0.027f,0.846f,0.0f,//61
            0.0f,0.946f,0.0f,//62
            0.3870f,0.7720f,0.0f,//63

            0.4855f,0.7141f,0.0f,//64,
            0.4818f,0.3844f,0.0f,//65
            0.785f,0.027f,0.0f,//66

            0.785f,-0.027f,0.0f,//67
            0.885f,0.0f,0.0f,//68

            


        };

        //Triangulos Amarillos
        uint[] _indices1 = {  // note that we start from 0!
            0,1,2,
            2,3,4,
            5,6,7,
            7,8,4,
            12,19,20,
            20,19,21,
            21,22,23,
            13,24,25,
            24,25,26,
            26,27,28,
            14,29,30,
            29,30,31,
            15,32,33,
            32,33,34,
            1,2,51,
            2,4,51,
            4,7,51,
            7,6,51,
            38,52,31,
            31,52,39,
            34,40,53,
            35,53,41,
            56,60,61,
            60,61,62,
            64,57,63,
            59,66,67,
            66,67,68
            
        };  
        //Triangulos Rojos
        uint[] _indices2 = {  // note that we start from 0!
            0,2,3,
            4,3,8,
            7,8,5,
            0,3,9,
            3,8,10,
            5,8,11,
        };

        //Triangulos Morados Claros
        uint[] _indices3 = {  // note that we start from 0!
            9,3,10,
            8,10,11,
            12,9,0, 
            5,11,13,
            14,9,10,
            10,11,15

        };

        //Triangulos Azul oscuro
        uint[] _indices4 = {  // note that we start from 0!
            12,9,14,
            14,10,15,
            15,11,13,
            12,14,16,
            14,17,15,
            15,13,18,
            23,38,35,
            39,36,40,
            37,41,28,
            23,42,38,
            39,43,40,
            41,44,28
        };

        //Triangulos Verde Oscuro
        uint[] _indices5 = {  // note that we start from 0!
            16,19,12,
            30,14,17,
            15,33,18,
            19,16,35,
            30,17,36,
            33,18,37,
            45,23,42,
            42,38,46,
            47,43,39,
            40,43,48,
            41,49,44,
            28,50,27,
            28,44,50,
            22,45,23,
            38,46,52,
            52,47,39,
            40,48,53,
            53,49,41

        };

        //Triangulos Rojo Oscuro
        uint[] _indices6 = {  // note that we start from 0!
            16,29,14,
            17,32,15,
            18,24,13,
            18,24,37,
            17,32,36,
            16,29,35
        };

        //Triangulos VioletashaderAzulClaro
        uint[] _indices7 = {  // note that we start from 0!
            21,19,35,
            35,29,31,
            30,31,36,
            32,36,34,
            33,34,37,
            37,24,26,
            21,23,35,
            37,28,26,
            35,38,31,
            31,36,39,
            36,40,34,
            34,41,37,

        };

        //Triangulos Azul Claro
        uint[] _indices8 = {  // note that we start from 0!
            54,22,45,
            46,52,47,
            53,48,49,
            56,54,45,
            46,57,47,
            48,49,58,
            27,50,55,
            59,55,50

        };

        private void invertirY(){
            for (int i = 1; i < _vertices.Length; i=i+3){
                _vertices[i]=_vertices[i]*(-1);
            }
        }

        private void invertirX(){
            for (int i = 0; i < _vertices.Length; i=i+3){
                _vertices[i]=_vertices[i]*(-1);
            }
        }

        // I -> II ->  III -> IV
        //(X,Y) -> (-X,Y) -> (-X,-Y) -> (X,-Y)
        //InvertirX -> InvertirY -> InvertirX


        private int[] _vertexBufferObject = new int[32];
        private int[] _vertexArrayObject = new int[32];
        private Shader _shader;
        private int[] _elementBufferObject = new int[32];

        public Window(GameWindowSettings gameWindowSettings, NativeWindowSettings nativeWindowSettings)
            : base(gameWindowSettings, nativeWindowSettings)
        {
        }

         protected override void OnLoad()//Esto corre una vez
        {
            base.OnLoad();
            
            GL.ClearColor(0.2f, 0.3f, 0.3f, 1.0f);

            //================================Cuadrante 1===========================
            //===========Partes Amarillas=============
            //VBO
            _vertexBufferObject[0] = GL.GenBuffer();
            GL.BindBuffer(BufferTarget.ArrayBuffer, _vertexBufferObject[0]);
            GL.BufferData(BufferTarget.ArrayBuffer, _vertices.Length * sizeof(float), _vertices, BufferUsageHint.StaticDraw);
            //VAO
            _vertexArrayObject[0] = GL.GenVertexArray();
            GL.BindVertexArray(_vertexArrayObject[0]);
            GL.VertexAttribPointer(0, 3, VertexAttribPointerType.Float, false, 3 * sizeof(float), 0);
            GL.EnableVertexAttribArray(0);
            //EBO
            _elementBufferObject[0] = GL.GenBuffer();
            GL.BindBuffer(BufferTarget.ElementArrayBuffer, _elementBufferObject[0]);
            GL.BufferData(BufferTarget.ElementArrayBuffer, _indices1.Length * sizeof(uint), _indices1, BufferUsageHint.StaticDraw);

            //===========Partes Rojas=============
            //VBO
            _vertexBufferObject[4] = GL.GenBuffer();
            GL.BindBuffer(BufferTarget.ArrayBuffer, _vertexBufferObject[4]);
            GL.BufferData(BufferTarget.ArrayBuffer, _vertices.Length * sizeof(float), _vertices, BufferUsageHint.StaticDraw);
            //VAO
            _vertexArrayObject[4] = GL.GenVertexArray();
            GL.BindVertexArray(_vertexArrayObject[4]);
            GL.VertexAttribPointer(0, 3, VertexAttribPointerType.Float, false, 3 * sizeof(float), 0);
            GL.EnableVertexAttribArray(0);
            //EBO
            _elementBufferObject[4] = GL.GenBuffer();
            GL.BindBuffer(BufferTarget.ElementArrayBuffer, _elementBufferObject[4]);
            GL.BufferData(BufferTarget.ElementArrayBuffer, _indices2.Length * sizeof(uint), _indices2, BufferUsageHint.StaticDraw);
            
            //===========Partes Morado Claro=============
            //VBO
            _vertexBufferObject[8] = GL.GenBuffer();
            GL.BindBuffer(BufferTarget.ArrayBuffer, _vertexBufferObject[8]);
            GL.BufferData(BufferTarget.ArrayBuffer, _vertices.Length * sizeof(float), _vertices, BufferUsageHint.StaticDraw);
            //VAO
            _vertexArrayObject[8] = GL.GenVertexArray();
            GL.BindVertexArray(_vertexArrayObject[8]);
            GL.VertexAttribPointer(0, 3, VertexAttribPointerType.Float, false, 3 * sizeof(float), 0);
            GL.EnableVertexAttribArray(0);
            //EBO
            _elementBufferObject[8] = GL.GenBuffer();
            GL.BindBuffer(BufferTarget.ElementArrayBuffer, _elementBufferObject[8]);
            GL.BufferData(BufferTarget.ElementArrayBuffer, _indices3.Length * sizeof(uint), _indices3, BufferUsageHint.StaticDraw);

            //===========Partes Azul Oscuro=============
            //VBO
            _vertexBufferObject[12] = GL.GenBuffer();
            GL.BindBuffer(BufferTarget.ArrayBuffer, _vertexBufferObject[12]);
            GL.BufferData(BufferTarget.ArrayBuffer, _vertices.Length * sizeof(float), _vertices, BufferUsageHint.StaticDraw);
            //VAO
            _vertexArrayObject[12] = GL.GenVertexArray();
            GL.BindVertexArray(_vertexArrayObject[12]);
            GL.VertexAttribPointer(0, 3, VertexAttribPointerType.Float, false, 3 * sizeof(float), 0);
            GL.EnableVertexAttribArray(0);
            //EBO
            _elementBufferObject[12] = GL.GenBuffer();
            GL.BindBuffer(BufferTarget.ElementArrayBuffer, _elementBufferObject[12]);
            GL.BufferData(BufferTarget.ElementArrayBuffer, _indices4.Length * sizeof(uint), _indices4, BufferUsageHint.StaticDraw);

            //===========Partes Verde Oscuro=============
            //VBO
            _vertexBufferObject[16] = GL.GenBuffer();
            GL.BindBuffer(BufferTarget.ArrayBuffer, _vertexBufferObject[16]);
            GL.BufferData(BufferTarget.ArrayBuffer, _vertices.Length * sizeof(float), _vertices, BufferUsageHint.StaticDraw);
            //VAO
            _vertexArrayObject[16] = GL.GenVertexArray();
            GL.BindVertexArray(_vertexArrayObject[16]);
            GL.VertexAttribPointer(0, 3, VertexAttribPointerType.Float, false, 3 * sizeof(float), 0);
            GL.EnableVertexAttribArray(0);
            //EBO
            _elementBufferObject[16] = GL.GenBuffer();
            GL.BindBuffer(BufferTarget.ElementArrayBuffer, _elementBufferObject[16]);
            GL.BufferData(BufferTarget.ElementArrayBuffer, _indices5.Length * sizeof(uint), _indices5, BufferUsageHint.StaticDraw);

            //===========Partes Rojo Oscuro=============
            //VBO
            _vertexBufferObject[20] = GL.GenBuffer();
            GL.BindBuffer(BufferTarget.ArrayBuffer, _vertexBufferObject[20]);
            GL.BufferData(BufferTarget.ArrayBuffer, _vertices.Length * sizeof(float), _vertices, BufferUsageHint.StaticDraw);
            //VAO
            _vertexArrayObject[20] = GL.GenVertexArray();
            GL.BindVertexArray(_vertexArrayObject[20]);
            GL.VertexAttribPointer(0, 3, VertexAttribPointerType.Float, false, 3 * sizeof(float), 0);
            GL.EnableVertexAttribArray(0);
            //EBO
            _elementBufferObject[20] = GL.GenBuffer();
            GL.BindBuffer(BufferTarget.ElementArrayBuffer, _elementBufferObject[20]);
            GL.BufferData(BufferTarget.ElementArrayBuffer, _indices6.Length * sizeof(uint), _indices6, BufferUsageHint.StaticDraw);

            //===========Partes Violeta=============
            //VBO
            _vertexBufferObject[24] = GL.GenBuffer();
            GL.BindBuffer(BufferTarget.ArrayBuffer, _vertexBufferObject[24]);
            GL.BufferData(BufferTarget.ArrayBuffer, _vertices.Length * sizeof(float), _vertices, BufferUsageHint.StaticDraw);
            //VAO
            _vertexArrayObject[24] = GL.GenVertexArray();
            GL.BindVertexArray(_vertexArrayObject[24]);
            GL.VertexAttribPointer(0, 3, VertexAttribPointerType.Float, false, 3 * sizeof(float), 0);
            GL.EnableVertexAttribArray(0);
            //EBO
            _elementBufferObject[24] = GL.GenBuffer();
            GL.BindBuffer(BufferTarget.ElementArrayBuffer, _elementBufferObject[24]);
            GL.BufferData(BufferTarget.ElementArrayBuffer, _indices7.Length * sizeof(uint), _indices7, BufferUsageHint.StaticDraw);

            //===========Partes Azul Claro=============
            //VBO
            _vertexBufferObject[28] = GL.GenBuffer();
            GL.BindBuffer(BufferTarget.ArrayBuffer, _vertexBufferObject[28]);
            GL.BufferData(BufferTarget.ArrayBuffer, _vertices.Length * sizeof(float), _vertices, BufferUsageHint.StaticDraw);
            //VAO
            _vertexArrayObject[28] = GL.GenVertexArray();
            GL.BindVertexArray(_vertexArrayObject[28]);
            GL.VertexAttribPointer(0, 3, VertexAttribPointerType.Float, false, 3 * sizeof(float), 0);
            GL.EnableVertexAttribArray(0);
            //EBO
            _elementBufferObject[28] = GL.GenBuffer();
            GL.BindBuffer(BufferTarget.ElementArrayBuffer, _elementBufferObject[28]);
            GL.BufferData(BufferTarget.ElementArrayBuffer, _indices8.Length * sizeof(uint), _indices8, BufferUsageHint.StaticDraw);

            invertirX();

            //================================Cuadrante 1I===========================
            //===========Partes Amarillas=============
            //VBO
            _vertexBufferObject[1] = GL.GenBuffer();
            GL.BindBuffer(BufferTarget.ArrayBuffer, _vertexBufferObject[1]);
            GL.BufferData(BufferTarget.ArrayBuffer, _vertices.Length * sizeof(float), _vertices, BufferUsageHint.StaticDraw);
            //VAO
            _vertexArrayObject[1] = GL.GenVertexArray();
            GL.BindVertexArray(_vertexArrayObject[1]);
            GL.VertexAttribPointer(0, 3, VertexAttribPointerType.Float, false, 3 * sizeof(float), 0);
            GL.EnableVertexAttribArray(0);
            //EBO
            _elementBufferObject[1] = GL.GenBuffer();
            GL.BindBuffer(BufferTarget.ElementArrayBuffer, _elementBufferObject[1]);
            GL.BufferData(BufferTarget.ElementArrayBuffer, _indices1.Length * sizeof(uint), _indices1, BufferUsageHint.StaticDraw);

            //===========Partes Rojas=============
            //VBO
            _vertexBufferObject[5] = GL.GenBuffer();
            GL.BindBuffer(BufferTarget.ArrayBuffer, _vertexBufferObject[5]);
            GL.BufferData(BufferTarget.ArrayBuffer, _vertices.Length * sizeof(float), _vertices, BufferUsageHint.StaticDraw);
            //VAO
            _vertexArrayObject[5] = GL.GenVertexArray();
            GL.BindVertexArray(_vertexArrayObject[5]);
            GL.VertexAttribPointer(0, 3, VertexAttribPointerType.Float, false, 3 * sizeof(float), 0);
            GL.EnableVertexAttribArray(0);
            //EBO
            _elementBufferObject[5] = GL.GenBuffer();
            GL.BindBuffer(BufferTarget.ElementArrayBuffer, _elementBufferObject[5]);
            GL.BufferData(BufferTarget.ElementArrayBuffer, _indices2.Length * sizeof(uint), _indices2, BufferUsageHint.StaticDraw);

            //===========Partes Morado Claro=============
            //VBO
            _vertexBufferObject[9] = GL.GenBuffer();
            GL.BindBuffer(BufferTarget.ArrayBuffer, _vertexBufferObject[9]);
            GL.BufferData(BufferTarget.ArrayBuffer, _vertices.Length * sizeof(float), _vertices, BufferUsageHint.StaticDraw);
            //VAO
            _vertexArrayObject[9] = GL.GenVertexArray();
            GL.BindVertexArray(_vertexArrayObject[9]);
            GL.VertexAttribPointer(0, 3, VertexAttribPointerType.Float, false, 3 * sizeof(float), 0);
            GL.EnableVertexAttribArray(0);
            //EBO
            _elementBufferObject[9] = GL.GenBuffer();
            GL.BindBuffer(BufferTarget.ElementArrayBuffer, _elementBufferObject[9]);
            GL.BufferData(BufferTarget.ElementArrayBuffer, _indices3.Length * sizeof(uint), _indices3, BufferUsageHint.StaticDraw);

            //===========Partes Azul Oscuro=============
            //VBO
            _vertexBufferObject[13] = GL.GenBuffer();
            GL.BindBuffer(BufferTarget.ArrayBuffer, _vertexBufferObject[13]);
            GL.BufferData(BufferTarget.ArrayBuffer, _vertices.Length * sizeof(float), _vertices, BufferUsageHint.StaticDraw);
            //VAO
            _vertexArrayObject[13] = GL.GenVertexArray();
            GL.BindVertexArray(_vertexArrayObject[13]);
            GL.VertexAttribPointer(0, 3, VertexAttribPointerType.Float, false, 3 * sizeof(float), 0);
            GL.EnableVertexAttribArray(0);
            //EBO
            _elementBufferObject[13] = GL.GenBuffer();
            GL.BindBuffer(BufferTarget.ElementArrayBuffer, _elementBufferObject[13]);
            GL.BufferData(BufferTarget.ElementArrayBuffer, _indices4.Length * sizeof(uint), _indices4, BufferUsageHint.StaticDraw);

            //===========Partes Verde Oscuro=============
            //VBO
            _vertexBufferObject[17] = GL.GenBuffer();
            GL.BindBuffer(BufferTarget.ArrayBuffer, _vertexBufferObject[17]);
            GL.BufferData(BufferTarget.ArrayBuffer, _vertices.Length * sizeof(float), _vertices, BufferUsageHint.StaticDraw);
            //VAO
            _vertexArrayObject[17] = GL.GenVertexArray();
            GL.BindVertexArray(_vertexArrayObject[17]);
            GL.VertexAttribPointer(0, 3, VertexAttribPointerType.Float, false, 3 * sizeof(float), 0);
            GL.EnableVertexAttribArray(0);
            //EBO
            _elementBufferObject[17] = GL.GenBuffer();
            GL.BindBuffer(BufferTarget.ElementArrayBuffer, _elementBufferObject[17]);
            GL.BufferData(BufferTarget.ElementArrayBuffer, _indices5.Length * sizeof(uint), _indices5, BufferUsageHint.StaticDraw);

            //===========Partes Rojo Oscuro=============
            //VBO
            _vertexBufferObject[21] = GL.GenBuffer();
            GL.BindBuffer(BufferTarget.ArrayBuffer, _vertexBufferObject[21]);
            GL.BufferData(BufferTarget.ArrayBuffer, _vertices.Length * sizeof(float), _vertices, BufferUsageHint.StaticDraw);
            //VAO
            _vertexArrayObject[21] = GL.GenVertexArray();
            GL.BindVertexArray(_vertexArrayObject[21]);
            GL.VertexAttribPointer(0, 3, VertexAttribPointerType.Float, false, 3 * sizeof(float), 0);
            GL.EnableVertexAttribArray(0);
            //EBO
            _elementBufferObject[21] = GL.GenBuffer();
            GL.BindBuffer(BufferTarget.ElementArrayBuffer, _elementBufferObject[21]);
            GL.BufferData(BufferTarget.ElementArrayBuffer, _indices6.Length * sizeof(uint), _indices6, BufferUsageHint.StaticDraw);

            //===========Partes Violeta=============
            //VBO
            _vertexBufferObject[25] = GL.GenBuffer();
            GL.BindBuffer(BufferTarget.ArrayBuffer, _vertexBufferObject[25]);
            GL.BufferData(BufferTarget.ArrayBuffer, _vertices.Length * sizeof(float), _vertices, BufferUsageHint.StaticDraw);
            //VAO
            _vertexArrayObject[25] = GL.GenVertexArray();
            GL.BindVertexArray(_vertexArrayObject[25]);
            GL.VertexAttribPointer(0, 3, VertexAttribPointerType.Float, false, 3 * sizeof(float), 0);
            GL.EnableVertexAttribArray(0);
            //EBO
            _elementBufferObject[25] = GL.GenBuffer();
            GL.BindBuffer(BufferTarget.ElementArrayBuffer, _elementBufferObject[25]);
            GL.BufferData(BufferTarget.ElementArrayBuffer, _indices7.Length * sizeof(uint), _indices7, BufferUsageHint.StaticDraw);

            //===========Partes Azul Claro=============
            //VBO
            _vertexBufferObject[29] = GL.GenBuffer();
            GL.BindBuffer(BufferTarget.ArrayBuffer, _vertexBufferObject[29]);
            GL.BufferData(BufferTarget.ArrayBuffer, _vertices.Length * sizeof(float), _vertices, BufferUsageHint.StaticDraw);
            //VAO
            _vertexArrayObject[29] = GL.GenVertexArray();
            GL.BindVertexArray(_vertexArrayObject[29]);
            GL.VertexAttribPointer(0, 3, VertexAttribPointerType.Float, false, 3 * sizeof(float), 0);
            GL.EnableVertexAttribArray(0);
            //EBO
            _elementBufferObject[29] = GL.GenBuffer();
            GL.BindBuffer(BufferTarget.ElementArrayBuffer, _elementBufferObject[29]);
            GL.BufferData(BufferTarget.ElementArrayBuffer, _indices8.Length * sizeof(uint), _indices8, BufferUsageHint.StaticDraw);

            invertirY();

            //================================Cuadrante 1II===========================
            //===========Partes Amarillas=============
            //VBO
            _vertexBufferObject[2] = GL.GenBuffer();
            GL.BindBuffer(BufferTarget.ArrayBuffer, _vertexBufferObject[2]);
            GL.BufferData(BufferTarget.ArrayBuffer, _vertices.Length * sizeof(float), _vertices, BufferUsageHint.StaticDraw);
            //VAO
            _vertexArrayObject[2] = GL.GenVertexArray();
            GL.BindVertexArray(_vertexArrayObject[2]);
            GL.VertexAttribPointer(0, 3, VertexAttribPointerType.Float, false, 3 * sizeof(float), 0);
            GL.EnableVertexAttribArray(0);
            //EBO
            _elementBufferObject[2] = GL.GenBuffer();
            GL.BindBuffer(BufferTarget.ElementArrayBuffer, _elementBufferObject[2]);
            GL.BufferData(BufferTarget.ElementArrayBuffer, _indices1.Length * sizeof(uint), _indices1, BufferUsageHint.StaticDraw);

            //===========Partes Rojas=============
            //VBO
            _vertexBufferObject[6] = GL.GenBuffer();
            GL.BindBuffer(BufferTarget.ArrayBuffer, _vertexBufferObject[6]);
            GL.BufferData(BufferTarget.ArrayBuffer, _vertices.Length * sizeof(float), _vertices, BufferUsageHint.StaticDraw);
            //VAO
            _vertexArrayObject[6] = GL.GenVertexArray();
            GL.BindVertexArray(_vertexArrayObject[6]);
            GL.VertexAttribPointer(0, 3, VertexAttribPointerType.Float, false, 3 * sizeof(float), 0);
            GL.EnableVertexAttribArray(0);
            //EBO
            _elementBufferObject[6] = GL.GenBuffer();
            GL.BindBuffer(BufferTarget.ElementArrayBuffer, _elementBufferObject[6]);
            GL.BufferData(BufferTarget.ElementArrayBuffer, _indices2.Length * sizeof(uint), _indices2, BufferUsageHint.StaticDraw);

            //===========Partes Morado Claro=============
            //VBO
            _vertexBufferObject[10] = GL.GenBuffer();
            GL.BindBuffer(BufferTarget.ArrayBuffer, _vertexBufferObject[10]);
            GL.BufferData(BufferTarget.ArrayBuffer, _vertices.Length * sizeof(float), _vertices, BufferUsageHint.StaticDraw);
            //VAO
            _vertexArrayObject[10] = GL.GenVertexArray();
            GL.BindVertexArray(_vertexArrayObject[10]);
            GL.VertexAttribPointer(0, 3, VertexAttribPointerType.Float, false, 3 * sizeof(float), 0);
            GL.EnableVertexAttribArray(0);
            //EBO
            _elementBufferObject[10] = GL.GenBuffer();
            GL.BindBuffer(BufferTarget.ElementArrayBuffer, _elementBufferObject[10]);
            GL.BufferData(BufferTarget.ElementArrayBuffer, _indices3.Length * sizeof(uint), _indices3, BufferUsageHint.StaticDraw);

            //===========Partes Azul Oscuro=============
            //VBO
            _vertexBufferObject[14] = GL.GenBuffer();
            GL.BindBuffer(BufferTarget.ArrayBuffer, _vertexBufferObject[14]);
            GL.BufferData(BufferTarget.ArrayBuffer, _vertices.Length * sizeof(float), _vertices, BufferUsageHint.StaticDraw);
            //VAO
            _vertexArrayObject[14] = GL.GenVertexArray();
            GL.BindVertexArray(_vertexArrayObject[14]);
            GL.VertexAttribPointer(0, 3, VertexAttribPointerType.Float, false, 3 * sizeof(float), 0);
            GL.EnableVertexAttribArray(0);
            //EBO
            _elementBufferObject[14] = GL.GenBuffer();
            GL.BindBuffer(BufferTarget.ElementArrayBuffer, _elementBufferObject[14]);
            GL.BufferData(BufferTarget.ElementArrayBuffer, _indices4.Length * sizeof(uint), _indices4, BufferUsageHint.StaticDraw);

            //===========Partes Verde Oscuro=============
            //VBO
            _vertexBufferObject[18] = GL.GenBuffer();
            GL.BindBuffer(BufferTarget.ArrayBuffer, _vertexBufferObject[18]);
            GL.BufferData(BufferTarget.ArrayBuffer, _vertices.Length * sizeof(float), _vertices, BufferUsageHint.StaticDraw);
            //VAO
            _vertexArrayObject[18] = GL.GenVertexArray();
            GL.BindVertexArray(_vertexArrayObject[18]);
            GL.VertexAttribPointer(0, 3, VertexAttribPointerType.Float, false, 3 * sizeof(float), 0);
            GL.EnableVertexAttribArray(0);
            //EBO
            _elementBufferObject[18] = GL.GenBuffer();
            GL.BindBuffer(BufferTarget.ElementArrayBuffer, _elementBufferObject[18]);
            GL.BufferData(BufferTarget.ElementArrayBuffer, _indices5.Length * sizeof(uint), _indices5, BufferUsageHint.StaticDraw);

            //===========Partes Rojo Oscuro=============
            //VBO
            _vertexBufferObject[22] = GL.GenBuffer();
            GL.BindBuffer(BufferTarget.ArrayBuffer, _vertexBufferObject[22]);
            GL.BufferData(BufferTarget.ArrayBuffer, _vertices.Length * sizeof(float), _vertices, BufferUsageHint.StaticDraw);
            //VAO
            _vertexArrayObject[22] = GL.GenVertexArray();
            GL.BindVertexArray(_vertexArrayObject[22]);
            GL.VertexAttribPointer(0, 3, VertexAttribPointerType.Float, false, 3 * sizeof(float), 0);
            GL.EnableVertexAttribArray(0);
            //EBO
            _elementBufferObject[22] = GL.GenBuffer();
            GL.BindBuffer(BufferTarget.ElementArrayBuffer, _elementBufferObject[22]);
            GL.BufferData(BufferTarget.ElementArrayBuffer, _indices6.Length * sizeof(uint), _indices6, BufferUsageHint.StaticDraw);

            //===========Partes Violeta=============
            //VBO
            _vertexBufferObject[26] = GL.GenBuffer();
            GL.BindBuffer(BufferTarget.ArrayBuffer, _vertexBufferObject[26]);
            GL.BufferData(BufferTarget.ArrayBuffer, _vertices.Length * sizeof(float), _vertices, BufferUsageHint.StaticDraw);
            //VAO
            _vertexArrayObject[26] = GL.GenVertexArray();
            GL.BindVertexArray(_vertexArrayObject[26]);
            GL.VertexAttribPointer(0, 3, VertexAttribPointerType.Float, false, 3 * sizeof(float), 0);
            GL.EnableVertexAttribArray(0);
            //EBO
            _elementBufferObject[26] = GL.GenBuffer();
            GL.BindBuffer(BufferTarget.ElementArrayBuffer, _elementBufferObject[26]);
            GL.BufferData(BufferTarget.ElementArrayBuffer, _indices7.Length * sizeof(uint), _indices7, BufferUsageHint.StaticDraw);

            //===========Partes Azul Claro=============
            //VBO
            _vertexBufferObject[30] = GL.GenBuffer();
            GL.BindBuffer(BufferTarget.ArrayBuffer, _vertexBufferObject[30]);
            GL.BufferData(BufferTarget.ArrayBuffer, _vertices.Length * sizeof(float), _vertices, BufferUsageHint.StaticDraw);
            //VAO
            _vertexArrayObject[30] = GL.GenVertexArray();
            GL.BindVertexArray(_vertexArrayObject[30]);
            GL.VertexAttribPointer(0, 3, VertexAttribPointerType.Float, false, 3 * sizeof(float), 0);
            GL.EnableVertexAttribArray(0);
            //EBO
            _elementBufferObject[30] = GL.GenBuffer();
            GL.BindBuffer(BufferTarget.ElementArrayBuffer, _elementBufferObject[30]);
            GL.BufferData(BufferTarget.ElementArrayBuffer, _indices8.Length * sizeof(uint), _indices8, BufferUsageHint.StaticDraw);

            invertirX();

            //================================Cuadrante 1V===========================
            //===========Partes Amarillas=============
            //VBO
            _vertexBufferObject[3] = GL.GenBuffer();
            GL.BindBuffer(BufferTarget.ArrayBuffer, _vertexBufferObject[3]);
            GL.BufferData(BufferTarget.ArrayBuffer, _vertices.Length * sizeof(float), _vertices, BufferUsageHint.StaticDraw);
            //VAO
            _vertexArrayObject[3] = GL.GenVertexArray();
            GL.BindVertexArray(_vertexArrayObject[3]);
            GL.VertexAttribPointer(0, 3, VertexAttribPointerType.Float, false, 3 * sizeof(float), 0);
            GL.EnableVertexAttribArray(0);
            //EBO
            _elementBufferObject[3] = GL.GenBuffer();
            GL.BindBuffer(BufferTarget.ElementArrayBuffer, _elementBufferObject[3]);
            GL.BufferData(BufferTarget.ElementArrayBuffer, _indices1.Length * sizeof(uint), _indices1, BufferUsageHint.StaticDraw);
            
            //===========Partes Rojas=============
            //VBO
            _vertexBufferObject[7] = GL.GenBuffer();
            GL.BindBuffer(BufferTarget.ArrayBuffer, _vertexBufferObject[7]);
            GL.BufferData(BufferTarget.ArrayBuffer, _vertices.Length * sizeof(float), _vertices, BufferUsageHint.StaticDraw);
            //VAO
            _vertexArrayObject[7] = GL.GenVertexArray();
            GL.BindVertexArray(_vertexArrayObject[7]);
            GL.VertexAttribPointer(0, 3, VertexAttribPointerType.Float, false, 3 * sizeof(float), 0);
            GL.EnableVertexAttribArray(0);
            //EBO
            _elementBufferObject[7] = GL.GenBuffer();
            GL.BindBuffer(BufferTarget.ElementArrayBuffer, _elementBufferObject[7]);
            GL.BufferData(BufferTarget.ElementArrayBuffer, _indices2.Length * sizeof(uint), _indices2, BufferUsageHint.StaticDraw);

            //===========Partes Morado Claro=============
            //VBO
            _vertexBufferObject[11] = GL.GenBuffer();
            GL.BindBuffer(BufferTarget.ArrayBuffer, _vertexBufferObject[11]);
            GL.BufferData(BufferTarget.ArrayBuffer, _vertices.Length * sizeof(float), _vertices, BufferUsageHint.StaticDraw);
            //VAO
            _vertexArrayObject[11] = GL.GenVertexArray();
            GL.BindVertexArray(_vertexArrayObject[11]);
            GL.VertexAttribPointer(0, 3, VertexAttribPointerType.Float, false, 3 * sizeof(float), 0);
            GL.EnableVertexAttribArray(0);
            //EBO
            _elementBufferObject[11] = GL.GenBuffer();
            GL.BindBuffer(BufferTarget.ElementArrayBuffer, _elementBufferObject[11]);
            GL.BufferData(BufferTarget.ElementArrayBuffer, _indices3.Length * sizeof(uint), _indices3, BufferUsageHint.StaticDraw);

            //===========Partes Azul Oscuro=============
            //VBO
            _vertexBufferObject[15] = GL.GenBuffer();
            GL.BindBuffer(BufferTarget.ArrayBuffer, _vertexBufferObject[15]);
            GL.BufferData(BufferTarget.ArrayBuffer, _vertices.Length * sizeof(float), _vertices, BufferUsageHint.StaticDraw);
            //VAO
            _vertexArrayObject[15] = GL.GenVertexArray();
            GL.BindVertexArray(_vertexArrayObject[15]);
            GL.VertexAttribPointer(0, 3, VertexAttribPointerType.Float, false, 3 * sizeof(float), 0);
            GL.EnableVertexAttribArray(0);
            //EBO
            _elementBufferObject[15] = GL.GenBuffer();
            GL.BindBuffer(BufferTarget.ElementArrayBuffer, _elementBufferObject[15]);
            GL.BufferData(BufferTarget.ElementArrayBuffer, _indices4.Length * sizeof(uint), _indices4, BufferUsageHint.StaticDraw);

            //===========Partes Verde Oscuro=============
            //VBO
            _vertexBufferObject[19] = GL.GenBuffer();
            GL.BindBuffer(BufferTarget.ArrayBuffer, _vertexBufferObject[19]);
            GL.BufferData(BufferTarget.ArrayBuffer, _vertices.Length * sizeof(float), _vertices, BufferUsageHint.StaticDraw);
            //VAO
            _vertexArrayObject[19] = GL.GenVertexArray();
            GL.BindVertexArray(_vertexArrayObject[19]);
            GL.VertexAttribPointer(0, 3, VertexAttribPointerType.Float, false, 3 * sizeof(float), 0);
            GL.EnableVertexAttribArray(0);
            //EBO
            _elementBufferObject[19] = GL.GenBuffer();
            GL.BindBuffer(BufferTarget.ElementArrayBuffer, _elementBufferObject[19]);
            GL.BufferData(BufferTarget.ElementArrayBuffer, _indices5.Length * sizeof(uint), _indices5, BufferUsageHint.StaticDraw);

            //===========Partes Rojo Oscuro=============
            //VBO
            _vertexBufferObject[23] = GL.GenBuffer();
            GL.BindBuffer(BufferTarget.ArrayBuffer, _vertexBufferObject[23]);
            GL.BufferData(BufferTarget.ArrayBuffer, _vertices.Length * sizeof(float), _vertices, BufferUsageHint.StaticDraw);
            //VAO
            _vertexArrayObject[23] = GL.GenVertexArray();
            GL.BindVertexArray(_vertexArrayObject[23]);
            GL.VertexAttribPointer(0, 3, VertexAttribPointerType.Float, false, 3 * sizeof(float), 0);
            GL.EnableVertexAttribArray(0);
            //EBO
            _elementBufferObject[23] = GL.GenBuffer();
            GL.BindBuffer(BufferTarget.ElementArrayBuffer, _elementBufferObject[23]);
            GL.BufferData(BufferTarget.ElementArrayBuffer, _indices6.Length * sizeof(uint), _indices6, BufferUsageHint.StaticDraw);

            //===========Partes Violeta=============
            //VBO
            _vertexBufferObject[27] = GL.GenBuffer();
            GL.BindBuffer(BufferTarget.ArrayBuffer, _vertexBufferObject[27]);
            GL.BufferData(BufferTarget.ArrayBuffer, _vertices.Length * sizeof(float), _vertices, BufferUsageHint.StaticDraw);
            //VAO
            _vertexArrayObject[27] = GL.GenVertexArray();
            GL.BindVertexArray(_vertexArrayObject[27]);
            GL.VertexAttribPointer(0, 3, VertexAttribPointerType.Float, false, 3 * sizeof(float), 0);
            GL.EnableVertexAttribArray(0);
            //EBO
            _elementBufferObject[27] = GL.GenBuffer();
            GL.BindBuffer(BufferTarget.ElementArrayBuffer, _elementBufferObject[27]);
            GL.BufferData(BufferTarget.ElementArrayBuffer, _indices7.Length * sizeof(uint), _indices7, BufferUsageHint.StaticDraw);

            //===========Partes Azul Claro=============
            //VBO
            _vertexBufferObject[31] = GL.GenBuffer();
            GL.BindBuffer(BufferTarget.ArrayBuffer, _vertexBufferObject[31]);
            GL.BufferData(BufferTarget.ArrayBuffer, _vertices.Length * sizeof(float), _vertices, BufferUsageHint.StaticDraw);
            //VAO
            _vertexArrayObject[31] = GL.GenVertexArray();
            GL.BindVertexArray(_vertexArrayObject[31]);
            GL.VertexAttribPointer(0, 3, VertexAttribPointerType.Float, false, 3 * sizeof(float), 0);
            GL.EnableVertexAttribArray(0);
            //EBO
            _elementBufferObject[31] = GL.GenBuffer();
            GL.BindBuffer(BufferTarget.ElementArrayBuffer, _elementBufferObject[31]);
            GL.BufferData(BufferTarget.ElementArrayBuffer, _indices8.Length * sizeof(uint), _indices8, BufferUsageHint.StaticDraw);

            // System.Console.WriteLine("[{0}]", string.Join(", ", _vertices));
            // invertir();
            // System.Console.WriteLine("[{0}]", string.Join(", ", _vertices));

            //GL.PolygonMode( MaterialFace.Front, PolygonMode.Line );

        }

        protected override void OnRenderFrame(FrameEventArgs e)
        {
            base.OnRenderFrame(e);
            

            GL.Clear(ClearBufferMask.ColorBufferBit);


            //================================Partes Amarillas===========================
            _shader = new Shader("Shaders/shader.vert", "Shaders/shaderAmarillo.frag");
            _shader.Use();
            //Cuadrante I
            GL.BindVertexArray(_vertexArrayObject[0]);
            GL.DrawElements(PrimitiveType.Triangles, _indices1.Length, DrawElementsType.UnsignedInt, 0);
            //Cuadrante II
            GL.BindVertexArray(_vertexArrayObject[1]);
            GL.DrawElements(PrimitiveType.Triangles, _indices1.Length, DrawElementsType.UnsignedInt, 0);
            //Cuadrante III
            GL.BindVertexArray(_vertexArrayObject[2]);
            GL.DrawElements(PrimitiveType.Triangles, _indices1.Length, DrawElementsType.UnsignedInt, 0);
            //Cuadrante IV
            GL.BindVertexArray(_vertexArrayObject[3]);
            GL.DrawElements(PrimitiveType.Triangles, _indices1.Length, DrawElementsType.UnsignedInt, 0);


            //================================Partes Rojas===========================
            _shader = new Shader("Shaders/shader.vert", "Shaders/shaderRojo.frag");
            _shader.Use();
            //Cuadrante I
            GL.BindVertexArray(_vertexArrayObject[4]);
            GL.DrawElements(PrimitiveType.Triangles, _indices2.Length, DrawElementsType.UnsignedInt, 0);
            //Cuadrante II
            GL.BindVertexArray(_vertexArrayObject[5]);
            GL.DrawElements(PrimitiveType.Triangles, _indices2.Length, DrawElementsType.UnsignedInt, 0);
            //Cuadrante III
            GL.BindVertexArray(_vertexArrayObject[6]);
            GL.DrawElements(PrimitiveType.Triangles, _indices2.Length, DrawElementsType.UnsignedInt, 0);
            //Cuadrante IV
            GL.BindVertexArray(_vertexArrayObject[7]);
            GL.DrawElements(PrimitiveType.Triangles, _indices2.Length, DrawElementsType.UnsignedInt, 0);

            //================================Partes Moradas Claras===========================
            _shader = new Shader("Shaders/shader.vert", "Shaders/shaderMoradoClaro.frag");
            _shader.Use();
            //Cuadrante I
            GL.BindVertexArray(_vertexArrayObject[8]);
            GL.DrawElements(PrimitiveType.Triangles, _indices3.Length, DrawElementsType.UnsignedInt, 0);
            //Cuadrante II
            GL.BindVertexArray(_vertexArrayObject[9]);
            GL.DrawElements(PrimitiveType.Triangles, _indices3.Length, DrawElementsType.UnsignedInt, 0);
            //Cuadrante III
            GL.BindVertexArray(_vertexArrayObject[10]);
            GL.DrawElements(PrimitiveType.Triangles, _indices3.Length, DrawElementsType.UnsignedInt, 0);
            //Cuadrante IV
            GL.BindVertexArray(_vertexArrayObject[11]);
            GL.DrawElements(PrimitiveType.Triangles, _indices3.Length, DrawElementsType.UnsignedInt, 0);

            //================================Partes Azul Oscuro===========================
            _shader = new Shader("Shaders/shader.vert", "Shaders/shaderAzulOscuro.frag");
            _shader.Use();
            //Cuadrante I
            GL.BindVertexArray(_vertexArrayObject[12]);
            GL.DrawElements(PrimitiveType.Triangles, _indices4.Length, DrawElementsType.UnsignedInt, 0);
            //Cuadrante II
            GL.BindVertexArray(_vertexArrayObject[13]);
            GL.DrawElements(PrimitiveType.Triangles, _indices4.Length, DrawElementsType.UnsignedInt, 0);
            //Cuadrante III
            GL.BindVertexArray(_vertexArrayObject[14]);
            GL.DrawElements(PrimitiveType.Triangles, _indices4.Length, DrawElementsType.UnsignedInt, 0);
            //Cuadrante IV
            GL.BindVertexArray(_vertexArrayObject[15]);
            GL.DrawElements(PrimitiveType.Triangles, _indices4.Length, DrawElementsType.UnsignedInt, 0);

            //================================Partes Verde Oscuro===========================
            _shader = new Shader("Shaders/shader.vert", "Shaders/shaderVerdeOscuro.frag");
            _shader.Use();
            //Cuadrante I
            GL.BindVertexArray(_vertexArrayObject[16]);
            GL.DrawElements(PrimitiveType.Triangles, _indices5.Length, DrawElementsType.UnsignedInt, 0);
            //Cuadrante II
            GL.BindVertexArray(_vertexArrayObject[17]);
            GL.DrawElements(PrimitiveType.Triangles, _indices5.Length, DrawElementsType.UnsignedInt, 0);
            //Cuadrante III
            GL.BindVertexArray(_vertexArrayObject[18]);
            GL.DrawElements(PrimitiveType.Triangles, _indices5.Length, DrawElementsType.UnsignedInt, 0);
            //Cuadrante IV
            GL.BindVertexArray(_vertexArrayObject[19]);
            GL.DrawElements(PrimitiveType.Triangles, _indices5.Length, DrawElementsType.UnsignedInt, 0);

            //================================Partes Rojo Oscuro===========================
            _shader = new Shader("Shaders/shader.vert", "Shaders/shaderRojoOscuro.frag");
            _shader.Use();
            //Cuadrante I
            GL.BindVertexArray(_vertexArrayObject[20]);
            GL.DrawElements(PrimitiveType.Triangles, _indices6.Length, DrawElementsType.UnsignedInt, 0);
            //Cuadrante II
            GL.BindVertexArray(_vertexArrayObject[21]);
            GL.DrawElements(PrimitiveType.Triangles, _indices6.Length, DrawElementsType.UnsignedInt, 0);
            //Cuadrante III
            GL.BindVertexArray(_vertexArrayObject[22]);
            GL.DrawElements(PrimitiveType.Triangles, _indices6.Length, DrawElementsType.UnsignedInt, 0);
            //Cuadrante IV
            GL.BindVertexArray(_vertexArrayObject[23]);
            GL.DrawElements(PrimitiveType.Triangles, _indices6.Length, DrawElementsType.UnsignedInt, 0);

            //================================Partes Violeta===========================
            _shader = new Shader("Shaders/shader.vert", "Shaders/shaderVioleta.frag");
            _shader.Use();
            //Cuadrante I
            GL.BindVertexArray(_vertexArrayObject[24]);
            GL.DrawElements(PrimitiveType.Triangles, _indices7.Length, DrawElementsType.UnsignedInt, 0);
            //Cuadrante II
            GL.BindVertexArray(_vertexArrayObject[25]);
            GL.DrawElements(PrimitiveType.Triangles, _indices7.Length, DrawElementsType.UnsignedInt, 0);
            //Cuadrante III
            GL.BindVertexArray(_vertexArrayObject[26]);
            GL.DrawElements(PrimitiveType.Triangles, _indices7.Length, DrawElementsType.UnsignedInt, 0);
            //Cuadrante IV
            GL.BindVertexArray(_vertexArrayObject[27]);
            GL.DrawElements(PrimitiveType.Triangles, _indices7.Length, DrawElementsType.UnsignedInt, 0);

            //================================Partes Azul Clarito===========================
            _shader = new Shader("Shaders/shader.vert", "Shaders/shaderAzulClaro.frag");
            _shader.Use();
            //Cuadrante I
            GL.BindVertexArray(_vertexArrayObject[28]);
            GL.DrawElements(PrimitiveType.Triangles, _indices7.Length, DrawElementsType.UnsignedInt, 0);
            //Cuadrante II
            GL.BindVertexArray(_vertexArrayObject[29]);
            GL.DrawElements(PrimitiveType.Triangles, _indices7.Length, DrawElementsType.UnsignedInt, 0);
            //Cuadrante III
            GL.BindVertexArray(_vertexArrayObject[30]);
            GL.DrawElements(PrimitiveType.Triangles, _indices7.Length, DrawElementsType.UnsignedInt, 0);
            //Cuadrante IV
            GL.BindVertexArray(_vertexArrayObject[31]);
            GL.DrawElements(PrimitiveType.Triangles, _indices7.Length, DrawElementsType.UnsignedInt, 0);

            
            SwapBuffers();
            return;

        }

         protected override void OnUpdateFrame(FrameEventArgs e)
        {
            base.OnUpdateFrame(e);

            var input = KeyboardState;

            if (input.IsKeyDown(Keys.Escape))
            {
                Close();
            }
        }

         protected override void OnResize(ResizeEventArgs e)
        {
            base.OnResize(e);

            GL.Viewport(0, 0, Size.X, Size.Y);
        }

        protected override void OnUnload()
        {
            // Unbind all the resources by binding the targets to 0/null.
            GL.BindBuffer(BufferTarget.ArrayBuffer, 0);
            GL.BindVertexArray(0);
            GL.UseProgram(0);

            // Delete all the resources.
            GL.DeleteBuffer(_vertexBufferObject[0]);
            GL.DeleteVertexArray(_vertexArrayObject[0]);

            GL.DeleteProgram(_shader.Handle);

            base.OnUnload();
        }
    }
}