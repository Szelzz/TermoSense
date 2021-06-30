
let = template = `
<style>
    html,
    body {
        margin: 0;
        padding: 0;
    }

    body {
        background-color: rgb(74, 174, 255);
    }

    .sun {
        margin: 0;
        width: 200px;
        position: absolute;
        top: 0;
        right: 0;
    }

    .house {
        width: 600px;
        height: 300px;

        margin: 200px auto;
    }

    .text-outside {
        left: 60px;
    }

    .text-inside {
        color: white;
        left: 0;
        text-align: center;
        width: 100%
    }

    .temperature {
        position: absolute;
        text-align: center;
        top: 350px;
        font-family: Arial;
        font-size: 50px;
        font-weight: bold;
    }
</style>


<div class="text-inside temperature">`+ insideTemperature + `°C</div>
<div class="text-outside temperature">` + outsideTemperature + `°C</div>
<svg class="sun" viewBox="0 0 104 103" version="1.1" xmlns="http://www.w3.org/2000/svg"
    xmlns:xlink="http://www.w3.org/1999/xlink" xml:space="preserve" xmlns:serif="http://www.serif.com/"
    style="fill-rule:evenodd;clip-rule:evenodd;stroke-linecap:round;stroke-linejoin:round;stroke-miterlimit:1.5;">
    <g>
        <clipPath id="_clip1">
            <rect x="0.69" y="0.19" width="102.765" height="102.567" />
        </clipPath>
        <g clip-path="url(#_clip1)">
            <path d="M53.646,0c-0,27.614 22.385,50 50,50l-0,-50l-50,0Z" style="fill:#ffe200;" />
            <g>
                <path d="M3.836,8.716l99.619,-8.716"
                    style="fill:none;stroke:#ffe200;stroke-width:3.82px;stroke-dasharray:7.64,19.09,0,0;" />
                <path d="M94.74,99.81l8.715,-99.62"
                    style="fill:none;stroke:#ffe200;stroke-width:3.82px;stroke-dasharray:7.64,19.09,0,0;" />
                <path d="M13.015,42.452l90.631,-42.262"
                    style="fill:none;stroke:#ffe200;stroke-width:3.82px;stroke-dasharray:7.64,19.09,0,0;" />
                <path d="M61.194,90.821l42.261,-90.631"
                    style="fill:none;stroke:#ffe200;stroke-width:3.82px;stroke-dasharray:7.64,19.09,0,0;" />
                <path d="M32.935,70.711l70.711,-70.711"
                    style="fill:none;stroke:#ffe200;stroke-width:3.82px;stroke-dasharray:7.64,19.09,0,0;" />
            </g>
        </g>
    </g>
</svg>
<div class="house">
    <svg width="100%" height="100%" viewBox="0 0 121 127" version="1.1" xmlns="http://www.w3.org/2000/svg"
        xmlns:xlink="http://www.w3.org/1999/xlink" xml:space="preserve" xmlns:serif="http://www.serif.com/"
        style="fill-rule:evenodd;clip-rule:evenodd;stroke-linejoin:round;stroke-miterlimit:2;">
        <g id="house">
            <rect x="7.039" y="43.215" width="106.496" height="82.942" style="fill:#333;" />
            <path d="M60.287,0.032l59.802,44.927l-119.603,0l59.801,-44.927Z" style="fill:#333;" />
        </g>
    </svg>
</div>`;

document.write(template);