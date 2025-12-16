uniform sampler2D texture;
uniform float time;
uniform vec2 resolution;
uniform vec4 textColor; // цвет текста из SFML

void main()
{
    vec2 uv = gl_TexCoord[0].xy;

    // --- "дрожание" текста (сдвиг по X) ---
    uv.x += 0.001 * sin(time * 20.0 + uv.y * 50.0);
    /*if (mod(floor(uv.y * resolution.y / 20.0 + time), 30.0) < 1.0) {
        uv.x += 0.05 * sin(time * 100.0);
    }   */


    // Берём альфу из текстуры (глиф белый)
    vec4 glyph = texture2D(texture, uv);

    // Применяем цвет текста вручную
    vec4 color = vec4(textColor.rgb * glyph.a, glyph.a);

    // --- Двигающиеся scanlines ---
    float scanline = 0.3 * sin(uv.y * resolution.y * 0.5 + time * 20.0);
    color.rgb *= (1.0 - scanline);

    // --- Лёгкое мерцание яркости ---
    // float flicker = 0.57 + 0.03 * sin(time * 6.0);
    // color.rgb *= flicker;

    gl_FragColor = color;
}
