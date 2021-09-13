using OpenTK.Graphics.OpenGL4;
using OpenTK.Windowing.Common;
using OpenTK.Windowing.GraphicsLibraryFramework;
using OpenTK.Windowing.Desktop;

namespace Tarea2V2{
    public class Window : GameWindow {
        float[] _vertices = {
            0.0f, 0.0f, 0.0f,

            -0.06f, -0.0f, 0.0f,
            -0.1f, -0.0f, 0.0f,
            -0.08f, 0.06f, 0.0f,

             0.034f, 0.097f, 0.0f,
            -0.017f,0.06f,0.0f,
            -0.03f,0.097f,0.0f,

             0.105f,0.0f,0.0f,
             0.0855f,0.06f,0.0f,
             0.053f,0.037f,0.0f,

             -0.128f,0.096f,0.0f, 
             -0.15f,0.04f,0.0f,
             -0.2f,0.0f,0.0f,

             -0.08f,0.132f,0.0f,
             -0.063f, 0.19f, 0.0f,
             -0.013f, 0.158f,0.0f,

             0.046f, 0.162f,0.0f,
             0.1f,0.12f,0.0f,
             0.165f, 0.135f,0.0f,

             0.147f,0.07f,0.0f,
             0.16f,0.0f,0.0f,
             0.20f,0.0f,0.0f,

             0.18f,0.06f,0.0f,


            

            

        };

        //Indices de la parte morada
        uint[] _indices1 = {  // note that we start from 0!
            1,2,3,
            3,5,6,
            5,6,4,
            7,8,9,
            4,8,9,
            
        };  
        //Indices de la parte amarilla
        uint[] _indices2 = {  // note that we start from 0!
            0,1,3, 
            0,3,5,
            0,5,4,
            0,4,9,
            0,7,9,
            2,3,10,
            2,10,11,
            2,11,12,
            10,3,6,
            10,6, 13,
            6,13,14,
            6,14,15,
            15,6,16,
            6,16,4,
            4,16,8,
            16,8,17,
            8,17,18,
            8,18,19,
            8,19,20,
            8,20,7

        };
        uint[] _indices3 = {  // note that we start from 0!
            0,3
            
        };

        private void invertir(){
            for (int i = 1; i < _vertices.Length; i=i+3){
                _vertices[i]=_vertices[i]*(-1);
            }
        }

        private int[] _vertexBufferObject = new int[6];
        private int[] _vertexArrayObject = new int[6];
        private Shader _shader;
        private int[] _elementBufferObject = new int[6];

        public Window(GameWindowSettings gameWindowSettings, NativeWindowSettings nativeWindowSettings)
            : base(gameWindowSettings, nativeWindowSettings)
        {
        }

         protected override void OnLoad()//Esto corre una vez
        {
            base.OnLoad();
            
            GL.ClearColor(0.2f, 0.3f, 0.3f, 1.0f);
            //Parte Morada Arriba
            _vertexBufferObject[0] = GL.GenBuffer();
            // The second argument is the handle to our buffer.
            GL.BindBuffer(BufferTarget.ArrayBuffer, _vertexBufferObject[0]);
            GL.BufferData(BufferTarget.ArrayBuffer, _vertices.Length * sizeof(float), _vertices, BufferUsageHint.StaticDraw);
            _vertexArrayObject[0] = GL.GenVertexArray();
            GL.BindVertexArray(_vertexArrayObject[0]);
            GL.VertexAttribPointer(0, 3, VertexAttribPointerType.Float, false, 3 * sizeof(float), 0);
            // Enable variable 0 in the shader.
            GL.EnableVertexAttribArray(0);
            _elementBufferObject[0] = GL.GenBuffer();
            GL.BindBuffer(BufferTarget.ElementArrayBuffer, _elementBufferObject[0]);
            GL.BufferData(BufferTarget.ElementArrayBuffer, _indices1.Length * sizeof(uint), _indices1, BufferUsageHint.StaticDraw);

            //Parte amarilla arriba
            _vertexBufferObject[1] = GL.GenBuffer();
            // The second argument is the handle to our buffer.
            GL.BindBuffer(BufferTarget.ArrayBuffer, _vertexBufferObject[1]);
            GL.BufferData(BufferTarget.ArrayBuffer, _vertices.Length * sizeof(float), _vertices, BufferUsageHint.StaticDraw);
            _vertexArrayObject[1] = GL.GenVertexArray();
            GL.BindVertexArray(_vertexArrayObject[1]);
            GL.VertexAttribPointer(0, 3, VertexAttribPointerType.Float, false, 3 * sizeof(float), 0);
            // Enable variable 0 in the shader.
            GL.EnableVertexAttribArray(0);
            _elementBufferObject[1] = GL.GenBuffer();
            GL.BindBuffer(BufferTarget.ElementArrayBuffer, _elementBufferObject[1]);
            GL.BufferData(BufferTarget.ElementArrayBuffer, _indices2.Length * sizeof(uint), _indices2, BufferUsageHint.StaticDraw);

            //Lineas negras arriba
            _vertexBufferObject[2] = GL.GenBuffer();
            // The second argument is the handle to our buffer.
            GL.BindBuffer(BufferTarget.ArrayBuffer, _vertexBufferObject[2]);
            GL.BufferData(BufferTarget.ArrayBuffer, _vertices.Length * sizeof(float), _vertices, BufferUsageHint.StaticDraw);
            _vertexArrayObject[2] = GL.GenVertexArray();
            GL.BindVertexArray(_vertexArrayObject[2]);
            GL.VertexAttribPointer(0, 3, VertexAttribPointerType.Float, false, 3 * sizeof(float), 0);
            // Enable variable 0 in the shader.
            GL.EnableVertexAttribArray(0);
            _elementBufferObject[2] = GL.GenBuffer();
            GL.BindBuffer(BufferTarget.ElementArrayBuffer, _elementBufferObject[2]);
            GL.BufferData(BufferTarget.ElementArrayBuffer, _indices3.Length * sizeof(uint), _indices2, BufferUsageHint.StaticDraw);

            System.Console.WriteLine("[{0}]", string.Join(", ", _vertices));
            invertir();
            System.Console.WriteLine("[{0}]", string.Join(", ", _vertices));

            //Parte Morada abajo
            _vertexBufferObject[3] = GL.GenBuffer();
            GL.BindBuffer(BufferTarget.ArrayBuffer, _vertexBufferObject[3]);
            GL.BufferData(BufferTarget.ArrayBuffer, _vertices.Length * sizeof(float), _vertices, BufferUsageHint.StaticDraw);
            _vertexArrayObject[3] = GL.GenVertexArray();
            GL.BindVertexArray(_vertexArrayObject[3]);
            GL.VertexAttribPointer(0, 3, VertexAttribPointerType.Float, false, 3 * sizeof(float), 0);
            // Enable variable 0 in the shader.
            GL.EnableVertexAttribArray(0);
            _elementBufferObject[3] = GL.GenBuffer();
            GL.BindBuffer(BufferTarget.ElementArrayBuffer, _elementBufferObject[3]);
            GL.BufferData(BufferTarget.ElementArrayBuffer, _indices1.Length * sizeof(uint), _indices1, BufferUsageHint.StaticDraw);

            //Parte amarilla abajo
            _vertexBufferObject[4] = GL.GenBuffer();
            // The second argument is the handle to our buffer.
            GL.BindBuffer(BufferTarget.ArrayBuffer, _vertexBufferObject[4]);
            GL.BufferData(BufferTarget.ArrayBuffer, _vertices.Length * sizeof(float), _vertices, BufferUsageHint.StaticDraw);
            _vertexArrayObject[4] = GL.GenVertexArray();
            GL.BindVertexArray(_vertexArrayObject[4]);
            GL.VertexAttribPointer(0, 3, VertexAttribPointerType.Float, false, 3 * sizeof(float), 0);
            // Enable variable 0 in the shader.
            GL.EnableVertexAttribArray(0);
            _elementBufferObject[4] = GL.GenBuffer();
            GL.BindBuffer(BufferTarget.ElementArrayBuffer, _elementBufferObject[4]);
            GL.BufferData(BufferTarget.ElementArrayBuffer, _indices2.Length * sizeof(uint), _indices2, BufferUsageHint.StaticDraw);

            //Lineas negras debajo
            _vertexBufferObject[5] = GL.GenBuffer();
            // The second argument is the handle to our buffer.
            GL.BindBuffer(BufferTarget.ArrayBuffer, _vertexBufferObject[5]);
            GL.BufferData(BufferTarget.ArrayBuffer, _vertices.Length * sizeof(float), _vertices, BufferUsageHint.StaticDraw);
            _vertexArrayObject[5] = GL.GenVertexArray();
            GL.BindVertexArray(_vertexArrayObject[5]);
            GL.VertexAttribPointer(0, 3, VertexAttribPointerType.Float, false, 3 * sizeof(float), 0);
            // Enable variable 0 in the shader.
            GL.EnableVertexAttribArray(0);
            _elementBufferObject[5] = GL.GenBuffer();
            GL.BindBuffer(BufferTarget.ElementArrayBuffer, _elementBufferObject[5]);
            GL.BufferData(BufferTarget.ElementArrayBuffer, _indices2.Length * sizeof(uint), _indices3, BufferUsageHint.StaticDraw);

            //GL.PolygonMode( MaterialFace.Front, PolygonMode.Line );

        }

        protected override void OnRenderFrame(FrameEventArgs e)
        {
            base.OnRenderFrame(e);
            

            GL.Clear(ClearBufferMask.ColorBufferBit);


            //Partes amarillas
            _shader = new Shader("Shaders/shader.vert", "Shaders/shaderAmarillo.frag");
            _shader.Use();
            //Parte arriba
            // Bind the VAO
            GL.BindVertexArray(_vertexArrayObject[1]);
            // And then call our drawing function.
            GL.DrawElements(PrimitiveType.Triangles, _indices2.Length, DrawElementsType.UnsignedInt, 0);
            //Parte de abajo
            GL.BindVertexArray(_vertexArrayObject[4]);
            // And then call our drawing function.
            GL.DrawElements(PrimitiveType.Triangles, _indices2.Length, DrawElementsType.UnsignedInt, 0);

            // Bind the VAO
            //Partes moradas
            // Bind the shader
            _shader = new Shader("Shaders/shader.vert", "Shaders/shaderMorado.frag");
            _shader.Use();
            GL.BindVertexArray(_vertexArrayObject[0]);
            // And then call our drawing function.
            GL.DrawElements(PrimitiveType.Triangles, _indices1.Length, DrawElementsType.UnsignedInt, 0);

            // Bind the VAO
            GL.BindVertexArray(_vertexArrayObject[3]);
            // And then call our drawing function.
            GL.DrawElements(PrimitiveType.Triangles, _indices1.Length, DrawElementsType.UnsignedInt, 0);
           

            // //Partes Negras no salen chido todavía
            // _shader = new Shader("Shaders/shader.vert", "Shaders/shaderNegro.frag");
            // _shader.Use();
            // //Parte arriba
            // // Bind the VAO
            // GL.BindVertexArray(_vertexArrayObject[2]);
            // // And then call our drawing function.
            // GL.DrawElements(PrimitiveType.Lines, _indices3.Length, DrawElementsType.UnsignedInt, 0);
            // //Parte de abajo
            // // Bind the VAO
            // GL.BindVertexArray(_vertexArrayObject[5]);
            // // And then call our drawing function.
            // GL.DrawElements(PrimitiveType.Lines, _indices3.Length, DrawElementsType.UnsignedInt, 0);
            
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