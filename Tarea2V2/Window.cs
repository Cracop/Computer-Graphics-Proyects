using OpenTK.Graphics.OpenGL4;
using OpenTK.Windowing.Common;
using OpenTK.Windowing.GraphicsLibraryFramework;
using OpenTK.Windowing.Desktop;

namespace Tarea2V2{
    public class Window : GameWindow {
        float[] _vertices = {
            0.0f, 0.0f, 0.0f,

            -0.06f, 0.0f, 0.0f,
            -0.1f, 0.0f, 0.0f,
            -0.08f, 0.06f, 0.0f,

             0.034f, 0.097f, 0.0f,
            -0.017f,0.06f,0.0f,
            -0.03f,0.097f,0.0f,

             0.105f,0.0f,0.0f,
             0.0855f,0.06f,0.0f,
             0.053f,0.037f,0.0f,

        };

        uint[] _indices =
        {
            // Note that indices start at 0!
            0, 1, 3, // The first triangle will be the bottom-right half of the triangle
            1, 2, 3  // Then the second will be the top-right half of the triangle
        };

        //Indices de la parte morada
        uint[] _indices1 = {  // note that we start from 0!
            1,2,3,
            3,5,6,
            5,6,4,
            7,8,9,
            4,8,9
        };  
        //Indices de la parte amarilla
        uint[] _indices2 = {  // note that we start from 0!
            0,1,3, 
            0,3,14,
            0,14,13
        };

        private void invertir(){
            for (int i = 0; i < _vertices.Length; i=i+3){
                _vertices[i]=_vertices[i]*(-1);
            }
        }

        private int[] _vertexBufferObject = new int[3];
        private int[] _vertexArrayObject = new int[3];
        private Shader _shader;
        private int[] _elementBufferObject = new int[3];

        public Window(GameWindowSettings gameWindowSettings, NativeWindowSettings nativeWindowSettings)
            : base(gameWindowSettings, nativeWindowSettings)
        {
        }

         protected override void OnLoad()//Esto corre una vez
        {
            base.OnLoad();
            GL.ClearColor(0.2f, 0.3f, 0.3f, 1.0f);
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

            _shader = new Shader("Shaders/shader.vert", "Shaders/shaderMorado.frag");

            _shader.Use();
        }

        protected override void OnRenderFrame(FrameEventArgs e)
        {
            base.OnRenderFrame(e);
            invertir();

            GL.Clear(ClearBufferMask.ColorBufferBit);

            // Bind the shader
            _shader.Use();

            // Bind the VAO
            GL.BindVertexArray(_vertexArrayObject[0]);

            // And then call our drawing function.
            GL.DrawElements(PrimitiveType.Triangles, 30, DrawElementsType.UnsignedInt, 0);

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