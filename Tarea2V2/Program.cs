using OpenTK.Mathematics;
using OpenTK.Windowing.Desktop;
//Rodrigo Barrera 181935
namespace Tarea2V2
{
     public static class Program
    {
        private static void Main()
        {
            var nativeWindowSettings = new NativeWindowSettings()
            {
                Size = new Vector2i(800, 600),
                Title = "Rodrigo Barrera - 181935 - Teselaciones Penrose",
            };

            // To create a new window, create a class that extends GameWindow, then call Run() on it.
            using (var window = new Window(GameWindowSettings.Default, nativeWindowSettings))
            {
                window.Run();
            }

            // And that's it! That's all it takes to create a window with OpenTK.
        }
    }
}

